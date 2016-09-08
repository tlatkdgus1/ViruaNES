//////////////////////////////////////////////////////////////////////////
// Mapper067  SunSoft Mapper 3                                          //
//////////////////////////////////////////////////////////////////////////
void	Mapper067::Reset()
{
	irq_enable = 0;
	irq_counter = 0;
	irq_latch = 0;

	SetPROM_32K_Bank( 0, 1, PROM_8K_SIZE-2, PROM_8K_SIZE-1 );

	SetVROM_4K_Bank( 0, 0 );
	SetVROM_4K_Bank( 4, VROM_4K_SIZE-1 );

	DWORD	crc = nes->rom->GetPROM_CRC();

	if( crc == 0x7f2a04bf ) {	// For Fantasy Zone 2(J)
		nes->SetRenderMethod( NES::PRE_ALL_RENDER );
	}
}

void	Mapper067::Write( WORD addr, BYTE data )
{
	switch( addr & 0xF800 ) {
		case	0x8800:
			SetVROM_2K_Bank( 0, data );
			break;
		case	0x9800:
			SetVROM_2K_Bank( 2, data );
			break;
		case	0xA800:
			SetVROM_2K_Bank( 4, data );
			break;
		case	0xB800:
			SetVROM_2K_Bank( 6, data );
			break;

		case	0xC800:
			irq_counter = irq_latch;
			irq_latch = data;
			break;
		case	0xD800:
			irq_enable = data & 0x10;
			break;

		case	0xE800:
			data &= 0x03;
			if( data == 0 )	     SetVRAM_Mirror( VRAM_VMIRROR );
			else if( data == 1 ) SetVRAM_Mirror( VRAM_HMIRROR );
			else if( data == 2 ) SetVRAM_Mirror( VRAM_MIRROR4L );
			else		     SetVRAM_Mirror( VRAM_MIRROR4H );
			break;

		case	0xF800:
			SetPROM_16K_Bank( 4, data );
			break;
	}
}

void	Mapper067::HSync( INT scanline )
{
	if( scanline >= 0 && scanline <= 239 ) {
		if( PPUREG[1] & (PPU_BGDISP_BIT|PPU_SPDISP_BIT) ) {
			if( irq_enable ) {
//				if( --irq_counter == 0xF6 ) {
				if( --irq_counter == 0xF7 ) {
					irq_counter = irq_latch;
					nes->cpu->IRQ_NotPending();
//					nes->cpu->IRQ();
				}
			}
		}
	}
}

void	Mapper067::SaveState( LPBYTE p )
{
	p[0] = irq_enable;
	p[1] = irq_counter;
	p[2] = irq_latch;
}

void	Mapper067::LoadState( LPBYTE p )
{
	irq_enable  = p[0];
	irq_counter = p[1];
	irq_latch   = p[2];
}
