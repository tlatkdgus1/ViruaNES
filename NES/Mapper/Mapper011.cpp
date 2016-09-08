//////////////////////////////////////////////////////////////////////////
// Mapper011  Color Dreams                                              //
//////////////////////////////////////////////////////////////////////////
void	Mapper011::Reset()
{
	SetPROM_32K_Bank( 0 );
	SetVROM_8K_Bank( 0 );

	SetVRAM_Mirror( VRAM_VMIRROR );
}

void	Mapper011::Write( WORD addr, BYTE data )
{
	SetPROM_32K_Bank( data&0x01 );
	SetVROM_8K_Bank( (data>>4)&0x07 );
}

