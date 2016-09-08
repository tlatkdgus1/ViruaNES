//////////////////////////////////////////////////////////////////////////
// Mapper064  Tengen Rambo-1                                            //
//////////////////////////////////////////////////////////////////////////
void	Mapper064::Reset()
{
	SetPROM_32K_Bank( PROM_8K_SIZE-1, PROM_8K_SIZE-1, PROM_8K_SIZE-1, PROM_8K_SIZE-1 );

	if( VROM_1K_SIZE ) {
		SetVROM_8K_Bank( 0 );
	}

	reg[0] = reg[1] = reg[2] = 0;

	irq_enable  = 0;
	irq_counter = 0;
	irq_latch   = 0;
}

void	Mapper064::Write( WORD addr, BYTE data )
{
	switch( addr&0xF003 ) {
		case	0x8000:
			reg[0] = data&0x0F;
			reg[1] = data&0x40;
			reg[2] = data&0x80;
			break;

		case	0x8001:
			switch( reg[0] ) {
				case	0x00:
					if( reg[2] ) {
						SetVROM_1K_Bank( 4, data+0 );
						SetVROM_1K_Bank( 5, data+1 );
					} else {
						SetVROM_1K_Bank( 0, data+0 );
						SetVROM_1K_Bank( 1, data+1 );
					}
					break;
				case	0x01:
					if( reg[2] ) {
						SetVROM_1K_Bank( 6, data+0 );
						SetVROM_1K_Bank( 7, data+1 );
					} else {
						SetVROM_1K_Bank( 2, data+0 );
						SetVROM_1K_Bank( 3, data+1 );
					}
					break;
				case	0x02:
					if( reg[2] ) {
						SetVROM_1K_Bank( 0, data );
					} else {
						SetVROM_1K_Bank( 4, data );
					}
					break;
				case	0x03:
					if( reg[2] ) {
						SetVROM_1K_Bank( 1, data );
					} else {
						SetVROM_1K_Bank( 5, data );
					}
					break;
				case	0x04:
					if( reg[2] ) {
						SetVROM_1K_Bank( 2, data );
					} else {
						SetVROM_1K_Bank( 6, data );
					}
					break;
				case	0x05:
					if( reg[2] ) {
						SetVROM_1K_Bank( 3, data );
					} else {
						SetVROM_1K_Bank( 7, data );
					}
					break;
				case	0x06:
					if( reg[1] ) {
						SetPROM_8K_Bank( 5, data );
					} else {
						SetPROM_8K_Bank( 4, data );
					}
					break;
				case	0x07:
					if( reg[1] ) {
						SetPROM_8K_Bank( 6, data );
					} else {
						SetPROM_8K_Bank( 5, data );
					}
					break;
				case	0x08:
					SetVROM_1K_Bank( 1, data );
					break;
				case	0x09:
					SetVROM_1K_Bank( 3, data );
					break;
				case	0x0F:
					if( reg[1] ) {
						SetPROM_8K_Bank( 4, data );
					} else {
						SetPROM_8K_Bank( 6, data );
					}
					break;
			}
			break;

		case	0xA000:
			if( data&0x01 ) SetVRAM_Mirror( VRAM_HMIRROR );
			else		SetVRAM_Mirror( VRAM_VMIRROR );
			break;

		case	0xC000:
			irq_latch = data;
			irq_counter = irq_latch;
			break;
		case	0xC001:
			irq_counter = irq_latch;
			break;
		case	0xE000:
			irq_enable = 0;
			irq_counter = irq_latch;
			break;
		case	0xE001:
			irq_enable = 0xFF;
			irq_counter = irq_latch;
			break;
	}
}

void	Mapper064::HSync( INT scanline )
{
	if( (scanline >= 0 && scanline <= 239) ) {
		if( nes->ppu->IsDispON() ) {
			if( irq_enable ) {
				if( !(--irq_counter) ) {
					irq_counter = irq_latch;
					nes->cpu->IRQ_NotPending();
				}
			}
		}
	}
}

void	Mapper064::SaveState( LPBYTE p )
{
	p[0] = reg[0];
	p[1] = reg[1];
	p[2] = reg[2];
	p[3] = irq_enable;
	p[4] = irq_counter;
	p[5] = irq_latch;
}

void	Mapper064::LoadState( LPBYTE p )
{
	reg[0] = p[0];
	reg[1] = p[1];
	reg[2] = p[2];
	irq_enable  = p[3];
	irq_counter = p[4];
	irq_latch   = p[5];
}
