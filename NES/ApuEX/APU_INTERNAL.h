//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      APU Internal                                                    //
//                                                           Norix      //
//                                               written     2001/09/18 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#ifndef	__APU_INTERNAL_INCLUDED__
#define	__APU_INTERNAL_INCLUDED__

#define	WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "typedef.h"
#include "macro.h"

#include "APU_INTERFACE.h"
#include "nes.h"

class	APU_INTERNAL : public APU_INTERFACE
{
public:
	APU_INTERNAL();
	~APU_INTERNAL();

	void	SetParent( NES* parent ) { nes = parent; }

	void	Reset( INT nRate );
	void	Setup( INT nRate );
	void	Write( WORD addr, BYTE data );
	BYTE	Read( WORD addr );
	INT	Process( INT channel );

	void	WriteSync( WORD addr, BYTE data );
	BYTE	ReadSync( WORD addr );
	void	VSync();
	BOOL	Sync( INT cycles );

	INT	GetFreq( INT channel );
protected:
	typedef	struct {
		BYTE	reg[4];
		BYTE	enable;
		BYTE	ch_volume;

		INT	vbl_length;

		INT	phaseacc;
		INT	freq;
		INT	freq_limit;

		INT	output_vol;
		BYTE	fixed_envelope;
		BYTE	holdnote;
		BYTE	volume;

		INT	sweep_step;

		INT	sweep_phase;
		INT	sweep_decay;

		BYTE	sweep_complement;

		BYTE	sweep_on;
		BYTE	sweep_shift;
		BYTE	sweep_length;
		BYTE	sweep_inc;

		BYTE	env_vol;
		INT	env_step;
		INT	env_phase;
		INT	env_decay;

		INT	adder;
		INT	duty_flip;

		// For sync;
		BYTE	sync_reg[4];
		BYTE	sync_enable;
		BYTE	sync_holdnote;
		INT	sync_freq;
		INT	sync_vbl_length;
	} RECTANGLE, *LPRECTANGLE;

	typedef	struct {
		BYTE	reg[4];
		BYTE	enable;

		INT	freq;
		INT	phaseacc;
		INT	output_vol;

		INT	adder;

		BYTE	holdnote;
		BYTE	linear_load_disable;

		INT	vbl_length;
		INT	linear_length;

		// For sync;
		BYTE	sync_reg[4];
		BYTE	sync_enable;
		BYTE	sync_holdnote;
		BYTE	sync_linear_load_disable;
		INT	sync_vbl_length;
		INT	sync_linear_length;
	} TRIANGLE, *LPTRIANGLE;

	typedef	struct {
		BYTE	reg[4];
		BYTE	enable;

		INT	vbl_length;

		INT	freq;
		INT	phaseacc;
		INT	output_vol;

		BYTE	fixed_envelope;
		BYTE	holdnote;
		BYTE	volume;

		BYTE	env_vol;
		INT	env_phase;
		INT	env_decay;

		BYTE	xor_tap;

		// For sync
		BYTE	sync_reg[4];
		BYTE	sync_enable;
		BYTE	sync_holdnote;
		INT	sync_vbl_length;
	} NOISE, *LPNOISE;

	typedef	struct {
		BYTE	reg[4];
		BYTE	enable;
		BYTE	looping;
		INT	freq;
		INT	phaseacc;
		INT	output_vol;
		WORD	address, cache_addr;
		INT	dmalength, cache_dmalength;
		BYTE	cur_byte;
		BYTE	dpcm_value;

		INT	dpcm_output_real, dpcm_output_fake, dpcm_output_old, dpcm_output_offset;

		// For sync
		BYTE	sync_reg[4];
		BYTE	sync_enable;
		BYTE	sync_looping;
		BYTE	sync_irq_gen;
		BYTE	sync_irq_enable;
		INT	sync_cycles, sync_cache_cycles;
		INT	sync_dmalength, sync_cache_dmalength;
	} DPCM, *LPDPCM;

	INT	RectangleRender( RECTANGLE& ch );
	INT	TriangleRender( TRIANGLE& ch );
	BYTE	Noise_shiftregister15( BYTE xor_tap );
	INT	NoiseRender( NOISE& ch );
	INT	DpcmRender( DPCM& ch );

	NES*	nes;

	BYTE	reg4015;
	BYTE	sync_reg4015;

	INT	sampling_rate;

	INT	cycle_rate;
	INT	count_rate;		// $4017
	INT	sync_count_rate;	// $4017

	RECTANGLE	ch0;
	RECTANGLE	ch1;
	TRIANGLE	ch2;
	NOISE		ch3;
	DPCM		ch4;

	// Tables
	static	INT	vbl_length[32];
	static	INT	freq_limit[8];
	static	INT	duty_lut[4];
	static	INT	noise_freq[16];
	static	INT	dpcm_cycles[16];

	static	INT	decay_lut[16];
	static	INT	vbl_lut[32];
	static	INT	trilength_lut[128];
private:
};

#endif	// !__APU_INTERNAL_INCLUDED__
