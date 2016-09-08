//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      Nintendo MMC5                                                   //
//                                                           Norix      //
//                                               written     2001/09/18 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#include "DebugOut.h"

#include "APU_MMC5.h"

#define	RECTANGLE_VOL_SHIFT	8
#define	DAOUT_VOL_SHIFT		6

INT	APU_MMC5::vbl_length[32] = {
    5, 127,   10,   1,   19,   2,   40,   3,
   80,   4,   30,   5,    7,   6,   13,   7,
    6,   8,   12,   9,   24,  10,   48,  11,
   96,  12,   36,  13,    8,  14,   16,  15
};

INT	APU_MMC5::duty_lut[4] = {
	 2,  4,  8, 12
};

INT	APU_MMC5::decay_lut[16];
INT	APU_MMC5::vbl_lut[32];

APU_MMC5::APU_MMC5()
{
	Reset( 22050 );	// âºÇÃé¸îgêî
}

APU_MMC5::~APU_MMC5()
{
}

void	APU_MMC5::Reset( INT nRate )
{
	ZeroMemory( &ch0, sizeof(ch0) );
	ZeroMemory( &ch1, sizeof(ch1) );

	reg5010 = reg5011 = reg5015 = 0;

	Setup( nRate );

	for( WORD addr = 0x5000; addr <= 0x5015; addr++ ) {
		Write( addr, 0 );
	}
}

void	APU_MMC5::Setup( INT nRate )
{
	cycle_rate = (INT)(APU_CLOCK*65536.0f/(float)nRate);

	// Create Tables
	INT	i;
	INT	samples = (INT)((float)nRate/60.0f);
	for( i = 0; i < 16; i++ )
		decay_lut[i] = (i+1)*samples*5;
	for( i = 0; i < 32; i++ )
		vbl_lut[i] = vbl_length[i]*samples*5;
}

void	APU_MMC5::Write( WORD addr, BYTE data )
{
	switch( addr ) {
		// MMC5 CH0 rectangle
		case	0x5000:
			ch0.reg[0] = data;
			ch0.volume         = data&0x0F;
			ch0.holdnote       = data&0x20;
			ch0.fixed_envelope = data&0x10;
			ch0.env_decay      = decay_lut[data&0x0F];
			ch0.duty_flip      = duty_lut[data>>6];
			break;
		case	0x5001:
			ch0.reg[1] = data;
			break;
		case	0x5002:
			ch0.reg[2] = data;
			ch0.freq = INT2FIX( ((ch0.reg[3]&0x07)<<8)+data+1 );
			break;
		case	0x5003:
			ch0.reg[3] = data;
			ch0.vbl_length = vbl_lut[data>>3];
			ch0.env_vol = 0;
			ch0.freq = INT2FIX( ((data&0x07)<<8)+ch0.reg[2]+1 );
			if( reg5015 & 0x01 )
				ch0.enable = 0xFF;
			break;
		// MMC5 CH1 rectangle
		case	0x5004:
			ch1.reg[0] = data;
			ch1.volume         = data&0x0F;
			ch1.holdnote       = data&0x20;
			ch1.fixed_envelope = data&0x10;
			ch1.env_decay      = decay_lut[data&0x0F];
			ch1.duty_flip      = duty_lut[data>>6];
			break;
		case	0x5005:
			ch1.reg[1] = data;
			break;
		case	0x5006:
			ch1.reg[2] = data;
			ch1.freq = INT2FIX( ((ch1.reg[3]&0x07)<<8)+data+1 );
			break;
		case	0x5007:
			ch1.reg[3] = data;
			ch1.vbl_length = vbl_lut[data>>3];
			ch1.env_vol = 0;
			ch1.freq = INT2FIX( ((data&0x07)<<8)+ch1.reg[2]+1 );
			if( reg5015 & 0x02 )
				ch1.enable = 0xFF;
			break;
		case	0x5010:
			reg5010 = data;
			break;
		case	0x5011:
			reg5011 = data;
			break;
		case	0x5012:
		case	0x5013:
		case	0x5014:
			break;
		case	0x5015:
			reg5015 = data;
			if( reg5015 & 0x01 ) {
				ch0.enable = 0xFF;
			} else {
				ch0.enable = 0;
				ch0.vbl_length = 0;
			}
			if( reg5015 & 0x02 ) {
				ch1.enable = 0xFF;
			} else {
				ch1.enable = 0;
				ch1.vbl_length = 0;
			}
			break;
	}
}

INT	APU_MMC5::Process( INT channel )
{
	switch( channel ) {
		case	0:
			return	RectangleRender( ch0 );
			break;
		case	1:
			return	RectangleRender( ch1 );
			break;
		case	2:
			return	(INT)reg5011 << DAOUT_VOL_SHIFT;
			break;
	}

	return	0;
}

INT	APU_MMC5::GetFreq( INT channel )
{
	if( channel == 0 || channel == 1 ) {
		RECTANGLE*	ch;
		if( channel == 0 ) ch = &ch0;
		else		   ch = &ch1;

		if( !ch->enable || ch->vbl_length <= 0 )
			return	0;
		if( ch->freq < INT2FIX( 8 ) )
			return	0;
		if( ch->fixed_envelope ) {
			if( !ch->volume )
				return	0;
		} else {
			if( !(0x0F-ch->env_vol) )
				return	0;
		}

		return	(INT)(256.0f*(FLOAT)APU_CLOCK/((FLOAT)FIX2INT(ch->freq)*16.0f));
	}

	return	0;
}

INT	APU_MMC5::RectangleRender( RECTANGLE& ch )
{
	if( !ch.enable || ch.vbl_length <= 0 )
		return	0;

	// vbl length counter
	if( !ch.holdnote )
		ch.vbl_length -= 5;

	// envelope unit
	ch.env_phase -= 5*4;
	while( ch.env_phase < 0 ) {
		ch.env_phase += ch.env_decay;
		if( ch.holdnote )
			ch.env_vol = (ch.env_vol+1)&0x0F;
		else if( ch.env_vol < 0x0F )
			ch.env_vol++;
	}

	if( ch.freq < INT2FIX( 8 ) )
		return	0;

	INT	volume;
	if( ch.fixed_envelope )
		volume = (INT)ch.volume;
	else
		volume = (INT)(0x0F-ch.env_vol);

	INT	output = volume<<RECTANGLE_VOL_SHIFT;

	ch.phaseacc -= cycle_rate;
	if( ch.phaseacc >= 0 ) {
		if( ch.adder < ch.duty_flip )
			ch.output_vol = output;
		else
			ch.output_vol = -output;
		return	ch.output_vol;
	}

	if( ch.freq > cycle_rate ) {
		ch.phaseacc += ch.freq;
		ch.adder = (ch.adder+1)&0x0F;
		if( ch.adder < ch.duty_flip )
			ch.output_vol = output;
		else
			ch.output_vol = -output;
	} else {
	// â¡èdïΩãœ
		INT	num_times, total;
		num_times = total = 0;
		while( ch.phaseacc < 0 ) {
			ch.phaseacc += ch.freq;
			ch.adder = (ch.adder+1)&0x0F;
			if( ch.adder < ch.duty_flip )
				total += output;
			else
				total -= output;
			num_times++;
		}
		ch.output_vol = total/num_times;
	}

	return	ch.output_vol;
}

