//////////////////////////////////////////////////////////////////////////
// Mapper086  Jaleco Early Mapper #2                                    //
//////////////////////////////////////////////////////////////////////////
void	Mapper086::Reset()
{
	SetPROM_32K_Bank( 0, 1, 2, 3 );
	SetVROM_8K_Bank( 0 );
}

void	Mapper086::WriteLow( WORD addr, BYTE data )
{
	if( addr == 0x6000 ) {
		SetPROM_32K_Bank( (data&0x30)>>4 );

		SetVROM_8K_Bank( (data&0x03)|((data & 0x40)>>4) );
	}
}
