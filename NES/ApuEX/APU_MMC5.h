//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      Nintendo MMC5                                                   //
//                                                           Norix      //
//                                               written     2001/09/18 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#ifndef	__APU_MMC5_INCLUDED__
#define	__APU_MMC5_INCLUDED__

#define	WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "typedef.h"
#include "macro.h"

#include "APU_INTERFACE.h"

class	APU_MMC5 : public APU_INTERFACE
{
public:
	APU_MMC5();
	~APU_MMC5();

	void	Reset( INT nRate );
	void	Setup( INT nRate );
	void	Write( WORD addr, BYTE data );
	INT	Process( INT channel );

	INT	GetFreq( INT channel );
protected:
	typedef	struct {
		BYTE	reg[4];
		BYTE	enable;

		INT	vbl_length;

		INT	phaseacc;
		INT	freq;

		INT	output_vol;
		BYTE	fixed_envelope;
		BYTE	holdnote;
		BYTE	volume;

		BYTE	env_vol;
		INT	env_phase;
		INT	env_decay;

		INT	adder;
		INT	duty_flip;
	} RECTANGLE, *LPRECTANGLE;

	INT	RectangleRender( RECTANGLE& ch );

	RECTANGLE	ch0, ch1;

	BYTE	reg5010;
	BYTE	reg5011;
	BYTE	reg5015;
	INT	cycle_rate;

	// Tables
	static	INT	vbl_length[32];
	static	INT	duty_lut[4];

	static	INT	decay_lut[16];
	static	INT	vbl_lut[32];
private:
};

#endif	// !__APU_MMC5_INCLUDED__
