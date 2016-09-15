//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      APU Internal                                                    //
//                                                           Norix      //
//                                               written     2001/09/18 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#include "DebugOut.h"
#include "APU_INTERNAL.h"

//
#define	RECTANGLE_OLDTYPE	1

// Volume shift
#define	RECTANGLE_VOL_SHIFT	8
#define	TRIANGLE_VOL_SHIFT	9
#define	NOISE_VOL_SHIFT		8
#define	DPCM_VOL_SHIFT		8

INT	APU_INTERNAL::vbl_length[32] = {
    5, 127,   10,   1,   19,   2,   40,   3,
   80,   4,   30,   5,    7,   6,   13,   7,
    6,   8,   12,   9,   24,  10,   48,  11,
   96,  12,   36,  13,    8,  14,   16,  15
};

INT	APU_INTERNAL::freq_limit[8] = {
	0x03FF, 0x0555, 0x0666, 0x071C, 0x0787, 0x07C1, 0x07E0, 0x07F0
};
INT	APU_INTERNAL::duty_lut[4] = {
	 2,  4,  8, 12
};

INT	APU_INTERNAL::noise_freq[16] = {
	  4,    8,   16,   32,   64,   96,  128,  160,
	202,  254,  380,  508,  762, 1016, 2034, 4068
};

// DMC ?몭긏깓긞긏릶긡?긳깑
INT	APU_INTERNAL::dpcm_cycles[16] = {
	428, 380, 340, 320, 286, 254, 226, 214,
	190, 160, 142, 128, 106,  85,  72,  54
};

INT	APU_INTERNAL::decay_lut[16];
INT	APU_INTERNAL::vbl_lut[32];
INT	APU_INTERNAL::trilength_lut[128];

APU_INTERNAL::APU_INTERNAL()
{
	nes = NULL;

	::ZeroMemory( &ch0, sizeof(ch0) );
	::ZeroMemory( &ch1, sizeof(ch1) );
	::ZeroMemory( &ch2, sizeof(ch2) );
	::ZeroMemory( &ch3, sizeof(ch3) );
	::ZeroMemory( &ch4, sizeof(ch4) );

	reg4015 = sync_reg4015 = 0;
	count_rate = sync_count_rate = 5;

	sampling_rate = 22050;

	// 돹먠믦
	cycle_rate = (INT)(CPU_CLOCK*65536.0f/22050.0f);
}

APU_INTERNAL::~APU_INTERNAL()
{
}

void	APU_INTERNAL::Reset( INT nRate )
{
	ZeroMemory( &ch0, sizeof(ch0) );
	ZeroMemory( &ch1, sizeof(ch1) );
	ZeroMemory( &ch2, sizeof(ch2) );
	ZeroMemory( &ch3, sizeof(ch3) );
//	ZeroMemory( &ch4, sizeof(ch4) );

	// $4011궼룊딖돸궢궶궋
	ch4.enable = 0;
	ch4.dmalength = 0;

	ch0.sweep_complement = 0x00;
	ch1.sweep_complement = 0xFF;

	Setup( nRate );

	Write( 0x4015, 0x00 );

	WORD	addr;
	for( addr = 0x4000; addr <= 0x4010; addr++ ) {
		Write( addr, 0x00 );
	}
	Write( 0x4012, 0x00 );
	Write( 0x4013, 0x00 );
	Write( 0x4015, 0x00 );
	Write( 0x4017, 0xC0 );
}

void	APU_INTERNAL::Setup( INT nRate )
{
	sampling_rate = nRate;

	cycle_rate = (INT)(APU_CLOCK*65536.0f/(float)nRate);

	// Create Tables
	INT	i;
	INT	samples = (INT)((float)nRate/60.0f);
	for( i = 0; i < 16; i++ )
		decay_lut[i] = (i+1)*samples*5;
	for( i = 0; i < 32; i++ )
		vbl_lut[i] = vbl_length[i]*samples*5;
	for( i = 0; i < 128; i++ )
		trilength_lut[i] = i*samples*5;
}

// *맴버가 너무 많아 data위주로만 설명함 부가설명 부탁
// ch0 : APU_INTERNAL.h에 정의되어 있음 맴버 개많음 ㅂㄷㅂㄷ
// ch0.reg는 2번째 인자 그대로 들어감
// ch0의 나머지 맴버들은 data와 비트연산을 통해 넣음
// CH0~4까지 있으며 각각 다른 역할을 함
// CH0~1 : RECTANGLE 구조체, CH2 : TRIANGLE 구조체, CH3 : NOISE, CH4 : DPCM
// CH0~4까지는 1차적으로 필터링되어져온 addr 0x4000~0x4017을 4개씩 나눠 각각 사용한다.
// 또한 CH0~4까지는 4개씩 나누어 사용하기 때문에 각각 ch0.reg[0~3]까지 사용한다. 
void	APU_INTERNAL::Write( WORD addr, BYTE data )
{
	switch( addr ) {
		// CH0 rectangle #1
		case	0x4000:
			ch0.reg[0] = data;
			ch0.volume = data&0x0F;
			ch0.holdnote       = data&0x20;
			ch0.fixed_envelope = data&0x10;
			ch0.env_decay      = decay_lut[data&0x0F];
			ch0.duty_flip      = duty_lut[data>>6];
			break;
		case	0x4001:
			ch0.reg[1] = data;
			ch0.sweep_on    = data&0x80;
			ch0.sweep_inc   = data&0x08;
			ch0.sweep_shift = data&0x07;
			ch0.sweep_decay = decay_lut[(data>>4)&0x07];
			ch0.freq_limit  = freq_limit[data&0x07];
			ch0.sweep_phase = 0;	// Sweep궬궚떗맕벏딖
			break;
		case	0x4002:
			ch0.reg[2] = data;
			ch0.freq = ((ch0.reg[3]&0x07)<<8)+data;
			break;
		case	0x4003:
			ch0.reg[3] = data;
			ch0.vbl_length = vbl_lut[data>>3];
			ch0.freq = ((data&0x07)<<8)+ch0.reg[2];
			ch0.env_vol = 0;
			ch0.adder = 0;
			if( reg4015 & 0x01 )
				ch0.enable = 0xFF;
			break;
		// CH1 rectangle #2
		case	0x4004:
			ch1.reg[0] = data;
			ch1.volume         = data&0x0F;
			ch1.holdnote       = data&0x20;
			ch1.fixed_envelope = data&0x10;
			ch1.env_decay      = decay_lut[data&0x0F];
			ch1.duty_flip      = duty_lut[data>>6];
			break;
		case	0x4005:
			ch1.reg[1] = data;
			ch1.sweep_on    = data&0x80;
			ch1.sweep_inc   = data&0x08;
			ch1.sweep_shift = data&0x07;
			ch1.sweep_decay = decay_lut[(data>>4)&0x07];
			ch1.freq_limit  = freq_limit[data&0x07];
			ch1.sweep_phase = 0;	// Sweep궬궚떗맕벏딖
			break;
		case	0x4006:
			ch1.reg[2] = data;
			ch1.freq = ((ch1.reg[3]&0x07)<<8)+data;
			break;
		case	0x4007:
			ch1.reg[3] = data;
			ch1.vbl_length = vbl_lut[data>>3];
			ch1.freq = ((data&0x07)<<8)+ch1.reg[2];
			ch1.env_vol = 0;
			ch1.adder = 0;
			if( reg4015 & 0x02 )
				ch1.enable = 0xFF;
			break;
		// CH2 triangle
		case	0x4008:
			ch2.reg[0] = data;
			ch2.holdnote = data&0x80;
			if( !(data&0x7F) ) {
				ch2.enable = 0;
				ch2.linear_length = 0;	// ?귕
				ch2.linear_load_disable = 0;
			} else if( !ch2.linear_load_disable && ch2.enable ) {
				ch2.linear_length = trilength_lut[data&0x7F];
				ch2.linear_load_disable = 0xFF;
			}
			break;
		case	0x4009:	// Unused
			break;
		case	0x400A:
			ch2.reg[1] = data;
			ch2.freq = INT2FIX( ((ch2.reg[2]&0x07)<<8)+data+1 );
//			ch2.vbl_length = vbl_lut[ch2.reg[2]>>3];
			break;
		case	0x400B:
			ch2.reg[2] = data;
			ch2.freq = INT2FIX( ((data&0x07)<<8)+ch2.reg[1]+1 );
			ch2.vbl_length = vbl_lut[data>>3];

#if	1
			if( (ch2.reg[0]&0x7F) ) {
				ch2.linear_length = trilength_lut[ch2.reg[0]&0x7F];
//				ch2.linear_load_disable = 0xFF;
			} else {
//				ch2.linear_load_disable = 0;
			}
#else
			if( !ch2.linear_length ) {
				ch2.linear_load_disable = 0;
			} else {
				ch2.linear_load_disable = 0xFF;
			}
#endif
			if( reg4015 & 0x04 )
				ch2.enable = 0xFF;
			break;

		// CH3 noise
		case	0x400C:
			ch3.reg[0] = data;
			ch3.volume         = data&0x0F;
			ch3.holdnote       = data&0x20;
			ch3.fixed_envelope = data&0x10;
			ch3.env_decay      = decay_lut[data&0x0F];
			break;
		case	0x400D:	// Unused
			break;
		case	0x400E:
			ch3.reg[1] = data;
			ch3.freq = INT2FIX(noise_freq[data&0x0F]);
			ch3.xor_tap = (data&0x80)?0x40:0x02;
			break;
		case	0x400F:
			ch3.reg[2] = data;
			ch3.vbl_length = vbl_lut[data>>3];
			ch3.env_vol = 0;
			if( reg4015 & 0x08 )
				ch3.enable = 0xFF;
			break;
		// CH4 DPCM
		case	0x4010:
			ch4.reg[0] = data;
			ch4.freq = INT2FIX(dpcm_cycles[data&0x0F]);
			ch4.looping = data&0x40;
			break;
		case	0x4011:
			ch4.reg[1] = data&0x7F;
			if( !ch4.dmalength ) {
				ch4.dpcm_value = (data&0x7F)>>1;
			}
			break;
		case	0x4012:
			ch4.reg[2] = data;
			ch4.cache_addr = 0xC000+(WORD)(data<<6);
			break;
		case	0x4013:
			ch4.reg[3] = data;
			ch4.cache_dmalength = ((data<<4)+1)<<3;
			break;

		case	0x4015:
			reg4015 = data;
			if( !(data&0x01) ) {
				ch0.enable = 0;
				ch0.vbl_length = 0;
			}
			if( !(data&0x02) ) {
				ch1.enable = 0;
				ch1.vbl_length = 0;
			}
			if( !(data&0x04) ) {
				ch2.enable = 0;
				ch2.vbl_length = 0;
				ch2.linear_length = 0;
				ch2.linear_load_disable = 0;
			}
			if( !(data&0x08) ) {
				ch3.enable = 0;
				ch3.vbl_length = 0;
			}
			if( !(data&0x10) ) {
				ch4.enable = 0;
				ch4.dmalength = 0;
			} else {
				ch4.enable = 0xFF;
				if( !ch4.dmalength ) {
					ch4.address = ch4.cache_addr;
					ch4.dmalength = ch4.cache_dmalength;
				}
			}
			break;

		case	0x4017:
			if( data&0x80 ) count_rate = 4;
			else		count_rate = 5;
			break;

		default:
			break;
	}
}

BYTE	APU_INTERNAL::Read( WORD addr )
{
BYTE	data = addr>>8;

	if( addr == 0x4015 ) {
		data = 0;
		if( ch0.enable && ch0.vbl_length > 0 ) data |= 0x01;
		if( ch1.enable && ch1.vbl_length > 0 ) data |= 0x02;
		if( ch2.enable ) {
			if( !ch2.holdnote ) {
				if( ch2.vbl_length > 0 ) data |= 0x04;
			} else {
				if( ch2.linear_length > 0 ) data |= 0x04;
			}
		}
		if( ch3.enable && ch3.vbl_length > 0 ) data |= 0x08;
		if( ch4.enable && ch4.dmalength )      data |= 0x10;
//		if( ch4.irq_enable ) data |= 0x80; // Sync궳렳몧궢궲궇귡
	}

	return	data;
}

INT	APU_INTERNAL::Process( INT channel )
{
	switch( channel ) {
		case	0:
			return	RectangleRender( ch0 );
			break;
		case	1:
			return	RectangleRender( ch1 );
			break;
		case	2:
			return	TriangleRender( ch2 );
			break;
		case	3:
			return	NoiseRender( ch3 );
			break;
		case	4:
			return	DpcmRender( ch4 );
			break;
		default:
			return	0;
	}

	return	0;
}

void	APU_INTERNAL::WriteSync( WORD addr, BYTE data )
{
	switch( addr ) {
		// CH0 rectangle #1
		case	0x4000:
			ch0.sync_reg[0] = data;
			ch0.sync_holdnote = data&0x20;
			break;
		case	0x4001:
			ch0.sync_reg[1] = data;
			break;
		case	0x4002:
			ch0.sync_reg[2] = data;
			break;
		case	0x4003:
			ch0.sync_reg[3] = data;
			ch0.sync_vbl_length = (INT)vbl_length[data>>3]*5;
			if( sync_reg4015&0x01 )
				ch0.sync_enable = 0xFF;
			break;

		// CH1 rectangle #1
		case	0x4004:
			ch1.sync_reg[0] = data;
			ch1.sync_holdnote = data&0x20;
			break;
		case	0x4005:
			ch1.sync_reg[1] = data;
			break;
		case	0x4006:
			ch1.sync_reg[2] = data;
			break;
		case	0x4007:
			ch1.sync_reg[3] = data;
			ch1.sync_vbl_length = (INT)vbl_length[data>>3]*5;
			if( sync_reg4015&0x02 )
				ch1.sync_enable = 0xFF;
			break;

		// CH2 triangle
		case	0x4008:
			ch2.sync_reg[0] = data;
			ch2.sync_holdnote = data&0x80;
			if( !(data&0x7F) ) {
				ch2.sync_linear_length = 0;	// ?귕
				ch2.sync_linear_load_disable = 0;
			} else if( !ch2.sync_linear_load_disable ) {
				ch2.sync_linear_length = data&0x7F;
				ch2.sync_linear_load_disable = 0xFF;
			}
			break;
		case	0x4009:	// Unused
			ch2.sync_reg[1] = data;
			break;
		case	0x400A:
			ch2.sync_reg[2] = data;
			ch2.sync_vbl_length = vbl_length[ch2.sync_reg[3]>>3]*5;

			if( ch2.sync_reg[0]&0x7F ) {
				ch2.sync_linear_length = ch2.sync_reg[0]&0x7F;
				ch2.sync_linear_load_disable = 0xFF;
			} else {
				ch2.sync_linear_load_disable = 0;
			}

			if( sync_reg4015 & 0x04 )
				ch2.sync_enable = 0xFF;
			break;
		case	0x400B:
			ch2.sync_reg[3] = data;
			ch2.sync_vbl_length = vbl_length[data>>3]*5;

			if( ch2.sync_reg[0]&0x7F ) {
				ch2.sync_linear_length = ch2.sync_reg[0]&0x7F;
				ch2.sync_linear_load_disable = 0xFF;
			} else {
				ch2.sync_linear_load_disable = 0;
			}

			if( sync_reg4015 & 0x04 )
				ch2.sync_enable = 0xFF;
			break;

		// CH3 noise
		case	0x400C:
			ch3.sync_reg[0] = data;
			ch3.sync_holdnote = data&0x20;
			break;
		case	0x400D: // Unused
			ch3.sync_reg[1] = data;
			break;
		case	0x400E:
			ch3.sync_reg[2] = data;
			break;
		case	0x400F:
			ch3.sync_reg[3] = data;
			ch3.sync_vbl_length = (INT)vbl_length[data>>3]*5;
			if( sync_reg4015&0x08 )
				ch3.sync_enable = 0xFF;
			break;

		// CH4 DPCM
		case	0x4010:
			ch4.sync_reg[0] = data;
			ch4.sync_cache_cycles = dpcm_cycles[data&0x0F];
			ch4.sync_cycles = 0;
			ch4.sync_looping = data&0x40;
			ch4.sync_irq_gen = data&0x80;
			break;
		case	0x4011:
			ch4.sync_reg[1] = data;
			break;
		case	0x4012:
			ch4.sync_reg[2] = data;
			break;
		case	0x4013:
			ch4.sync_reg[3] = data;
			ch4.sync_cache_dmalength = ((data<<4)+1)<<3;
			break;

		case	0x4015:
			sync_reg4015 = data;

			if( !(data&0x01) ) {
				ch0.sync_enable = 0;
				ch0.sync_vbl_length = 0;
			}
			if( !(data&0x02) ) {
				ch1.sync_enable = 0;
				ch1.sync_vbl_length = 0;
			}
			if( !(data&0x04) ) {
				ch2.sync_enable = 0;
				ch2.sync_vbl_length = 0;
				ch2.sync_linear_length = 0;
				ch2.sync_linear_load_disable = 0;
			}
			if( !(data&0x08) ) {
				ch3.sync_enable = 0;
				ch3.sync_vbl_length = 0;
			}
			if( !(data&0x10) ) {
				ch4.sync_enable = 0;
				ch4.sync_dmalength = 0;
				ch4.sync_irq_enable = 0;
			} else {
				ch4.sync_enable = 0xFF;
				if( !ch4.sync_dmalength ) {
					ch4.sync_cycles = ch4.sync_cache_cycles;
					ch4.sync_dmalength = ch4.sync_cache_dmalength;
				}
			}
			break;

		case	0x4017:
			if( data&0x80 ) sync_count_rate = 4;
			else		sync_count_rate = 5;
			break;
	}
}

BYTE	APU_INTERNAL::ReadSync( WORD addr )
{
BYTE	data = addr>>8;

	if( addr == 0x4015 ) {
		data = 0;
		if( ch0.sync_enable && ch0.sync_vbl_length > 0 ) data |= 0x01;
		if( ch1.sync_enable && ch1.sync_vbl_length > 0 ) data |= 0x02;
		if( ch2.sync_enable ) {
			if( !ch2.sync_holdnote ) {
				if( ch2.sync_vbl_length > 0 ) data |= 0x04;
			} else {
				if( ch2.sync_linear_length > 0 ) data |= 0x04;
			}
		}
		if( ch3.sync_enable && ch3.sync_vbl_length > 0 ) data |= 0x08;
		if( ch4.sync_enable && ch4.sync_dmalength )      data |= 0x10;
		if( ch4.sync_irq_enable ) data |= 0x80;
	}

	return	data;
}

void	APU_INTERNAL::VSync()
{

	if( ch0.sync_enable && !ch0.sync_holdnote && ch0.sync_vbl_length > 0 )
		ch0.sync_vbl_length -= sync_count_rate;
	if( ch1.sync_enable && !ch1.sync_holdnote && ch1.sync_vbl_length > 0 )
		ch1.sync_vbl_length -= sync_count_rate;

	if( ch2.sync_enable ) {
		if( !ch2.sync_holdnote ) {
			if( ch2.sync_vbl_length > 0 ) {
				ch2.sync_vbl_length -= 5;
			}
			if( ch2.sync_linear_length > 0 ) {
				ch2.sync_linear_length--;
			}
		}
	}
	if( ch3.sync_enable && !ch3.sync_holdnote && ch3.sync_vbl_length > 0 )
		ch3.sync_vbl_length -= sync_count_rate;
}

inline	BOOL	APU_INTERNAL::Sync( INT cycles )
{
BOOL	bIRQ = FALSE;
DPCM&	ch = ch4;

	if( ch.sync_enable ) {
		if( ch.sync_dmalength ) {
			if( (ch.sync_cycles-=cycles) <= 0 ) {
				ch.sync_cycles += ch.sync_cache_cycles;

#if	0
				ch.sync_dmalength--;
				if( !ch.sync_dmalength ) {
					if( ch.sync_looping ) {
						ch.sync_dmalength = ch.sync_cache_dmalength;
//					} else if( ch.sync_irq_gen ) {
//						ch.sync_irq_enable = 0xFF;
					}
				} else if( ch.sync_dmalength < 8 ) {
					if( ch.sync_irq_gen ) {
						ch.sync_irq_enable = 0xFF;
					}
				}
#else
				if( !(--ch.sync_dmalength) ) {
					if( ch.sync_looping ) {
						ch.sync_dmalength = ch.sync_cache_dmalength;
					} else if( ch.sync_irq_gen ) {
						ch.sync_irq_enable = 0xFF;
					}
				}
#endif
			}
		}
	}
	if( ch.sync_irq_enable ) {
		bIRQ = TRUE;
//DEBUGOUT( "DMC IRQ b!!\n" );
	}

	return	bIRQ;
}

INT	APU_INTERNAL::GetFreq( INT channel )
{
INT	freq = 0;

	// Rectangle
	if( channel == 0 || channel == 1 ) {
		RECTANGLE* ch;
		if( channel == 0 ) ch = &ch0;
		else		   ch = &ch1;
		if( !ch->enable || ch->vbl_length <= 0 )
			return	0;
		if( ch->freq < 8 || (!ch->sweep_inc && ch->freq > ch->freq_limit) )
			return	0;

		if( ch->fixed_envelope ) {
			if( !ch->volume )
				return	0;
		} else {
			if( !(0x0F-ch->env_vol) )
				return	0;
		}

		freq = (((INT)ch->reg[3]&0x07)<<8)+(INT)ch->reg[2]+1;
		freq = (INT)(16.0f*CPU_CLOCK/(FLOAT)freq);
		return	freq;
	}

	// Triangle
	if( channel == 2 ) {
		if( !ch2.enable || ch2.vbl_length <= 0 )
			return	0;
		if( ch2.linear_length <= 0 || ch2.freq < INT2FIX(8) )
			return	0;
		freq = (((INT)ch2.reg[2]&0x07)<<8)+(INT)ch2.reg[1]+1;
		freq = (INT)(8.0f*CPU_CLOCK/(FLOAT)freq);
		return	freq;
	}

	// Noise
	if( channel == 3 ) {
		if( !ch3.enable || ch3.vbl_length <= 0 )
			return	0;
		if( ch3.fixed_envelope ) {
			if( !ch3.volume )
				return	0;
		} else {
			if( !(ch3.env_vol^0x0F) )
				return	0;
		}
		return	1;
	}

	// DPCM
	if( channel == 4 ) {
		if( ch4.enable && ch4.dmalength )
			return	1;
	}

	return	0;
}

INT	APU_INTERNAL::RectangleRender( RECTANGLE& ch )
{
	if( !ch.enable || ch.vbl_length <= 0 )
		return	0;

	// vbl length counter
	if( !ch.holdnote ) {
		ch.vbl_length -= count_rate;
	}

	// envelope unit
	ch.env_phase -= count_rate*4;
	while( ch.env_phase <= 0 ) {
		ch.env_phase += ch.env_decay;
		if( ch.holdnote )
			ch.env_vol = (ch.env_vol+1)&0x0F;
		else if( ch.env_vol < 0x0F )
			ch.env_vol++;
	}

	if( ch.fixed_envelope )
		ch.ch_volume = ch.volume;
	else
		ch.ch_volume = 0x0F-ch.env_vol;

	if( ch.freq < 8 || (!ch.sweep_inc && ch.freq > ch.freq_limit) ) {
		return	0;
	}

	// frequency sweep unit
	if( ch.sweep_on && ch.sweep_shift ) {
		ch.sweep_phase -= count_rate*2;
		while( ch.sweep_phase <= 0 ) {
			ch.sweep_phase += ch.sweep_decay;
			if( ch.sweep_inc ) {	// High frequency
				if( !ch.sweep_complement )
					ch.freq += ~(ch.freq >> ch.sweep_shift); // CH 0
				else
					ch.freq -= (ch.freq >> ch.sweep_shift);	// CH 1
			} else {		// Low frequency
				ch.freq += (ch.freq >> ch.sweep_shift);
			}
		}
	}

	INT	output = ch.ch_volume<<RECTANGLE_VOL_SHIFT;

	ch.phaseacc -= cycle_rate;
	if( ch.phaseacc >= 0 ) {
		if( ch.adder < ch.duty_flip )
			ch.output_vol = output;
		else
			ch.output_vol = -output;
		return	ch.output_vol;
	}

	INT	freq = INT2FIX( ch.freq+1 );
	if( freq > cycle_rate ) {
		ch.phaseacc += freq;
		ch.adder = (ch.adder+1)&0x0F;
		if( ch.adder < ch.duty_flip )
			ch.output_vol = output;
		else
			ch.output_vol = -output;
	} else {
	// 돿뢣빟뗉
		INT	num_times, total;
		num_times = total = 0;
		while( ch.phaseacc < 0 ) {
			ch.phaseacc += freq;
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

INT	APU_INTERNAL::TriangleRender( TRIANGLE& ch )
{
	if( !ch.enable || ch.vbl_length <= 0 || ch.linear_length <= 0 )
		return	ch.output_vol;

	if( !ch.holdnote ) {
		if( ch.vbl_length > 0 ) {
			ch.vbl_length -= 5;
		}
		if( ch.linear_length > 0 ) {
			ch.linear_length -= 5*4;
		}
	}

	if( ch.vbl_length <= 0 || ch.linear_length <= 0 ) {
		ch2.linear_load_disable = 0;
		ch2.enable = 0;
	}

	if( ch.freq < INT2FIX(8) ) {
		return	ch.output_vol;
	}

	ch.phaseacc -= cycle_rate;
	if( ch.phaseacc >= 0 )
		return	ch.output_vol;

	if( ch.freq > cycle_rate ) {
		ch.phaseacc += ch.freq;
		ch.adder = (ch.adder+1)&0x1F;
		if( ch.adder < 0x10 ) {
			ch.output_vol = (ch.adder&0x0F)<<TRIANGLE_VOL_SHIFT;
		} else {
			ch.output_vol = (0x0F-(ch.adder&0x0F))<<TRIANGLE_VOL_SHIFT;
		}
	} else {
	// 돿뢣빟뗉
		INT	num_times, total;
		num_times = total = 0;
		while( ch.phaseacc < 0 ) {
			ch.phaseacc += ch.freq;
			ch.adder = (ch.adder+1)&0x1F;
			if( ch.adder < 0x10 ) {
				total += (ch.adder&0x0F)<<TRIANGLE_VOL_SHIFT;
			} else {
				total += (0x0F-(ch.adder&0x0F))<<TRIANGLE_VOL_SHIFT;
			}
			num_times++;
		}
		ch.output_vol = total/num_times;
	}

	INT	vol = 0x100-ch4.reg[1]/2;
	ch.output_vol = ch.output_vol * vol / 0x100;
	return	ch.output_vol;
}

BYTE	APU_INTERNAL::Noise_shiftregister15( BYTE xor_tap )
{
static int sreg = 0x4000;
int	bit0, bit14;

	bit0 = sreg&1;
	if( sreg&xor_tap ) bit14 = bit0^1;
	else		   bit14 = bit0^0;
	sreg >>= 1;
	sreg |= (bit14<<14);
	return	(bit0^1);
}

INT	APU_INTERNAL::NoiseRender( NOISE& ch )
{
	if( !ch.enable || ch.vbl_length <= 0 )
		return	0;

	// vbl length counter
	if( !ch.holdnote )
		ch.vbl_length -= count_rate;

	// envelope unit
	ch.env_phase -= count_rate*4;
	while( ch.env_phase < 0 ) {
		ch.env_phase += ch.env_decay;
		if( ch.holdnote )
			ch.env_vol = (ch.env_vol+1)&0x0F;
		else if( ch.env_vol < 0x0F )
			ch.env_vol++;
	}

//	if( ch.freq < INT2FIX(8) ) {	// 뼰뫪룉뿚뫮랉궴빓궞궑궶궋댴궻?긃긞긏(뙅?뚼궘)
//		return	0;
//	}

	INT	output;
	if( ch.fixed_envelope )
		output = ch.volume<<NOISE_VOL_SHIFT;	// fixed volume
	else
		output = (ch.env_vol^0x0F)<<NOISE_VOL_SHIFT;

	ch.phaseacc -= cycle_rate;
	if( ch.phaseacc >= 0 )
		return	ch.output_vol;

	if( ch.freq > cycle_rate ) {
		ch.phaseacc += ch.freq;
		if( Noise_shiftregister15(ch.xor_tap) )
			ch.output_vol = output;
		else
			ch.output_vol = -output;
	} else {
		INT	num_times, total;
		num_times = total = 0;
		while( ch.phaseacc < 0 ) {
			ch.phaseacc += ch.freq;
			if( Noise_shiftregister15(ch.xor_tap) )
				total += output;
			else
				total -= output;
			num_times++;
		}
		ch.output_vol = total/num_times;
	}

	return	ch.output_vol;
}

INT	APU_INTERNAL::DpcmRender( DPCM& ch )
{
	if( ch.dmalength ) {
		ch.phaseacc -= cycle_rate;

		while( ch.phaseacc < 0 ) {
			ch.phaseacc += ch.freq;
			if( !(ch.dmalength&7) ) {
				ch.cur_byte = nes->Read( ch.address );
				if( 0xFFFF == ch.address )
					ch.address = 0x8000;
				else
					ch.address++;
			}

			if( !(--ch.dmalength) ) {
				if( ch.looping ) {
					ch.address = ch.cache_addr;
					ch.dmalength = ch.cache_dmalength;
				} else {
					ch.enable = 0;
					break;
				}
			}
			// positive delta
			if( ch.cur_byte&(1<<((ch.dmalength&7)^7)) ) {
				if( ch.dpcm_value < 0x3F )
					ch.dpcm_value += 1;
			} else {
			// negative delta
				if( ch.dpcm_value > 1 )
					ch.dpcm_value -= 1;
			}
		}
	}

#if	0
	ch.dpcm_output_real = (INT)(ch.reg[1]&0x01)+(INT)ch.dpcm_value*2;
	// 벺뢯궢궫뭠귩랁룣궥귡(TEST)
	if( abs(ch.dpcm_output_real-ch.dpcm_output_old) > 0x30 ) {
		ch.dpcm_output_offset = ch.dpcm_output_real - ch.dpcm_output_old;
	} else {
		if( ch.dpcm_output_offset > 0 ) {
			ch.dpcm_output_offset--;
		} else if( ch.dpcm_output_offset < 0 ) {
			ch.dpcm_output_offset++;
		}
	}
	ch.dpcm_output_old = ch.dpcm_output_real;
	ch.output_vol = (ch.dpcm_output_real-ch.dpcm_output_offset)<<DPCM_VOL_SHIFT;
#else
#if	1
	// 귽깛?긌뢑궋긵?긩귽긛긇긞긣(TEST)
	ch.dpcm_output_real = (INT)((ch.reg[1]&0x01)+ch.dpcm_value*2)-0x40;
	if( abs(ch.dpcm_output_real-ch.dpcm_output_fake) <= 8 ) {
		ch.dpcm_output_fake = ch.dpcm_output_real;
		ch.output_vol = (INT)ch.dpcm_output_real<<DPCM_VOL_SHIFT;
	} else {
		if( ch.dpcm_output_real > ch.dpcm_output_fake )
			ch.dpcm_output_fake += 8;
		else
			ch.dpcm_output_fake -= 8;
		ch.output_vol = (INT)ch.dpcm_output_fake<<DPCM_VOL_SHIFT;
	}
#else
//	ch.output_vol = (((INT)ch.reg[1]&0x01)+(INT)ch.dpcm_value*2)<<DPCM_VOL_SHIFT;
	ch.output_vol = ((((INT)ch.reg[1]&0x01)+(INT)ch.dpcm_value*2)-0x40)<<DPCM_VOL_SHIFT;
#endif
#endif
	return	ch.output_vol;
}

