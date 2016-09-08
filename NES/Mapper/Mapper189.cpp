//////////////////////////////////////////////////////////////////////////
// Mapper189  Street Fighter 2 Yoko/Master Fighter 2                    //
//////////////////////////////////////////////////////////////////////////
void	Mapper189::Reset()
{
	SetPROM_32K_Bank( PROM_8K_SIZE-4, PROM_8K_SIZE-3, PROM_8K_SIZE-2, PROM_8K_SIZE-1 );

	if( VROM_1K_SIZE ) {
		SetVROM_8K_Bank( 0 );
	}

	reg[0] = reg[1] = 0;

	chr01 = 0;
	chr23 = 2;
	chr4  = 4;
	chr5  = 5;
	chr6  = 6;
	chr7  = 7;
	SetBank_PPU();

	irq_enable  = 0;
	irq_counter = 0;
	irq_latch   = 0;
}

void	Mapper189::WriteLow( WORD addr, BYTE data )
{
	if( (addr & 0xFF00) == 0x4100 ) {
	// Street Fighter 2 YOKO
		SetPROM_32K_Bank( (data&0x30)>>4 );
	} else if( (addr & 0xFF00) == 0x6100 ) {
	// Master Fighter 2
		SetPROM_32K_Bank( data&0x03 );
	} else {
		Mapper::WriteLow( addr, data );
	}
}

void	Mapper189::Write( WORD addr, BYTE data )
{
	switch( addr&0xF001 ) {
		case	0x8000:
			reg[0] = data;
			SetBank_PPU();
			break;

		case	0x8001:
			reg[1] = data;
			SetBank_PPU();
			switch( reg[0] & 0x07 ) {
				case	0x00:
					chr01 = data & 0xFE;
					SetBank_PPU();
					break;
				case	0x01:
					chr23 = data & 0xFE;
					SetBank_PPU();
					break;
				case	0x02:
					chr4 = data;
					SetBank_PPU();
					break;
				case	0x03:
					chr5 = data;
					SetBank_PPU();
					break;
				case	0x04:
					chr6 = data;
					SetBank_PPU();
					break;
				case	0x05:
					chr7 = data;
					SetBank_PPU();
					break;
			}
			break;

		case	0xA000:
			if( data&0x01 ) SetVRAM_Mirror( VRAM_HMIRROR );
			else		SetVRAM_Mirror( VRAM_VMIRROR );
			break;

		case	0xC000:
			irq_counter = data;
			break;
		case	0xC001:
			irq_latch = data;
			break;
		case	0xE000:
			irq_enable = 0;
			break;
		case	0xE001:
			irq_enable = 0xFF;
			break;
	}
}

void	Mapper189::HSync( INT scanline )
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

void	Mapper189::SetBank_PPU()
{
	if( VROM_1K_SIZE ) {
		if( reg[0] & 0x80 ) {
			SetVROM_8K_Bank( chr4, chr5, chr6, chr7,
					 chr01, chr01+1, chr23, chr23+1 );
		} else {
			SetVROM_8K_Bank( chr01, chr01+1, chr23, chr23+1,
					 chr4, chr5, chr6, chr7 );
		}
	} else {
		if( reg[0] & 0x80 ) {
			SetCRAM_1K_Bank( 4, (chr01+0)&0x07 );
			SetCRAM_1K_Bank( 5, (chr01+1)&0x07 );
			SetCRAM_1K_Bank( 6, (chr23+0)&0x07 );
			SetCRAM_1K_Bank( 7, (chr23+1)&0x07 );
			SetCRAM_1K_Bank( 0, chr4&0x07 );
			SetCRAM_1K_Bank( 1, chr5&0x07 );
			SetCRAM_1K_Bank( 2, chr6&0x07 );
			SetCRAM_1K_Bank( 3, chr7&0x07 );
		} else {
			SetCRAM_1K_Bank( 0, (chr01+0)&0x07 );
			SetCRAM_1K_Bank( 1, (chr01+1)&0x07 );
			SetCRAM_1K_Bank( 2, (chr23+0)&0x07 );
			SetCRAM_1K_Bank( 3, (chr23+1)&0x07 );
			SetCRAM_1K_Bank( 4, chr4&0x07 );
			SetCRAM_1K_Bank( 5, chr5&0x07 );
			SetCRAM_1K_Bank( 6, chr6&0x07 );
			SetCRAM_1K_Bank( 7, chr7&0x07 );
		}
	}
}

void	Mapper189::SaveState( LPBYTE p )
{
	p[0] = reg[0];
	p[1] = reg[1];
	p[2] = chr01;
	p[3] = chr23;
	p[4] = chr4;
	p[5] = chr5;
	p[6] = chr6;
	p[7] = chr7;
	p[ 8] = irq_enable;
	p[ 9] = irq_counter;
	p[10] = irq_latch;
}

void	Mapper189::LoadState( LPBYTE p )
{
	reg[0] = p[0];
	reg[1] = p[1];
	chr01  = p[2];
	chr23  = p[3];
	chr4   = p[4];
	chr5   = p[5];
	chr6   = p[6];
	chr7   = p[7];

	irq_enable  = p[ 8];
	irq_counter = p[ 9];
	irq_latch   = p[10];
}
