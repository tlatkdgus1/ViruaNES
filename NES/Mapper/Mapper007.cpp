//////////////////////////////////////////////////////////////////////////
// Mapper007 AOROM/AMROM                                                //
//////////////////////////////////////////////////////////////////////////
void	Mapper007::Reset()
{
	patch = 0;

	SetPROM_32K_Bank( 0 );

	DWORD	crc = nes->rom->GetPROM_CRC();
	if( crc == 0x3c9fe649 ) {	// WWF Wrestlemania Challenge(U)
		SetVRAM_Mirror( VRAM_VMIRROR );
		patch = 1;
	}
}

void	Mapper007::Write( WORD addr, BYTE data )
{
	SetPROM_32K_Bank( (data & 0x07) );

	if( !patch ) {
		if( data & 0x10 ) SetVRAM_Mirror( VRAM_MIRROR4H );
		else		  SetVRAM_Mirror( VRAM_MIRROR4L );
	}
}
