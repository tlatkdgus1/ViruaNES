//////////////////////////////////////////////////////////////////////////
// Mapper016  Bandai Standard                                           //
//////////////////////////////////////////////////////////////////////////
void	Mapper016::Reset()
{
	patch = 0;

	reg[0] = reg[1] = reg[2] = 0;
	irq_enable = 0;
	irq_counter = 0;
	irq_latch = 0;
	irq_type = 0;

	outport = 0;
	eeprom_stat = 0;
	eeprom_mode = 0;
	eeprom_addr = 0;
	eeprom_data = 0;
	eeprom_wbit = 0;
	eeprom_rbit = 0;
	ZeroMemory( eeprom_cmd, sizeof(eeprom_cmd) );

	SetPROM_32K_Bank( 0, 1, PROM_8K_SIZE-2, PROM_8K_SIZE-1 );

	DWORD	crc = nes->rom->GetPROM_CRC();

	if( crc == 0x3f15d20d ) {	// Famicom Jump 2(J)
		patch = 1;
	}

	if( crc == 0x7fb799fd ) {	// Dragon Ball 2 - Dai Maou Fukkatsu(J)
	}
	if( crc == 0x6c6c2feb		// Dragon Ball 3 - Gokuu Den(J)
	 || crc == 0x8edeb257 ) {	// Dragon Ball 3 - Gokuu Den(J)(Alt)
	}
	if( crc == 0x31cd9903 ) {	// Dragon Ball Z - Kyoushuu! Saiya Jin(J)
//		nes->SetRenderMethod( NES::PRE_ALL_RENDER );
		irq_type = 1;
	}
	if( crc == 0xe49fc53e ) {	// Dragon Ball Z 2 - Gekishin Freeza!!(J)
//		nes->SetRenderMethod( NES::PRE_ALL_RENDER );
		irq_type = 1;
	}
	if( crc == 0x09499f4d ) {	// Dragon Ball Z 3 - Ressen Jinzou Ningen(J)
		irq_type = 1;
	}
	if( crc == 0x2e991109 ) {	// Dragon Ball Z Gaiden - Saiya Jin Zetsumetsu Keikaku (J)
//		nes->SetRenderMethod( NES::POST_RENDER );
	}
	if( crc == 0x146fb9c3 ) {	// SD Gundam Gaiden - Knight Gundam Monogatari(J)
	}
	if( crc == 0x170250de ) {	// Rokudenashi Blues(J)
		nes->SetRenderMethod( NES::PRE_ALL_RENDER );
	}

	if( !patch ) {
		nes->SetSAVERAM_SIZE( 128 );
	}
}

BYTE	Mapper016::ReadLow( WORD addr )
{
	if( patch ) {
		return	Mapper::ReadLow( addr );
	} else {
//DEBUGOUT( "RD $%04X=%02X\n", addr, outport );
//		if( addr == 0x6000 ) {
		if( (addr & 0x00FF) == 0x0000 ) {
			return	outport;
		}
	}
	return	0x00;
}

void	Mapper016::WriteLow( WORD addr, BYTE data )
{
	if( !patch ) {
		WriteSubA( addr, data );
	} else {
		Mapper::WriteLow( addr, data );
	}
}

void	Mapper016::Write( WORD addr, BYTE data )
{
	if( !patch ) {
		WriteSubA( addr, data );
	} else {
		WriteSubB( addr, data );
	}
}

static	BYTE	eeprom_addinc;

// Normal mapper #16
void	Mapper016::WriteSubA( WORD addr, BYTE data )
{
	switch( addr & 0x000F ) {
		case	0x0000:
		case	0x0001:
		case	0x0002:
		case	0x0003:
		case	0x0004:
		case	0x0005:
		case	0x0006:
		case	0x0007:
			if( VROM_1K_SIZE ) {
				SetVROM_1K_Bank( addr&0x0007, data );
			}
			break;

		case	0x0008:
			SetPROM_16K_Bank( 4, data );
			break;

		case	0x0009:
			data &= 0x03;
			if( data == 0 )	     SetVRAM_Mirror( VRAM_VMIRROR );
			else if( data == 1 ) SetVRAM_Mirror( VRAM_HMIRROR );
			else if( data == 2 ) SetVRAM_Mirror( VRAM_MIRROR4L );
			else		     SetVRAM_Mirror( VRAM_MIRROR4H );
			break;

		case	0x000A:
			irq_enable = data & 0x01;
			irq_counter = irq_latch;
			break;
		case	0x000B:
			irq_latch = (irq_latch & 0xFF00) | data;
			break;
		case	0x000C:
			irq_latch = ((INT)data << 8) | (irq_latch & 0x00FF);
			break;

		case	0x000D:
//DEBUGOUT( "WR $%04X=%02X\n", addr, data );
			if( data == 0x80 ) {
			// Reset
				eeprom_addr = 0;
				eeprom_mode = 0;
				eeprom_wbit = 0;
				eeprom_rbit = 0;
		        } else if( eeprom_cmd[3] == 0x00 && eeprom_cmd[2] == 0x20
				&& eeprom_cmd[1] == 0x60 && eeprom_cmd[0] == 0x40 && data == 0x00 ) {
			// Reset ?
			} else if( eeprom_cmd[3] == 0x00 && eeprom_cmd[2] == 0x40
				&& eeprom_cmd[1] == 0x60 && eeprom_cmd[0] == 0x20 && data == 0x00 ) {
			// Start command
				eeprom_wbit = 0x01;
				eeprom_rbit = 0x01;
				eeprom_data = 0;
				eeprom_mode = 0;
			} else if( eeprom_cmd[0] == 0x60 && data == 0xE0 ) {
			// Sync & Read
				if( !eeprom_mode ) {
				// Sync
					eeprom_wbit = 0x01;
					eeprom_rbit = 0x01;
					eeprom_data = 0;
					eeprom_mode = 1;
					eeprom_stat = 0x00;
					outport = eeprom_stat;
				} else {
				// Read
					eeprom_data = WRAM[eeprom_addr];
					if( eeprom_data & eeprom_rbit ) {
						eeprom_stat = 0x10;
					} else {
						eeprom_stat = 0x00;
					}
					outport = eeprom_stat;
					eeprom_rbit <<= 1;
					eeprom_wbit = 0x00;
				}
			} else if( eeprom_cmd[1] == 0x00 && eeprom_cmd[0] == 0x20 && data == 0x00 ) {
			// write 0
				eeprom_data &= ~eeprom_wbit;
				if( eeprom_wbit == 0x80 ) {
					if( eeprom_mode ) {
						WRAM[eeprom_addr] = eeprom_data;
					} else {
//						eeprom_addr = (eeprom_addr+1) & 0x7F;
						eeprom_addr = eeprom_data & 0x7F;
					}
					eeprom_wbit = 0x00;
				} else {
					eeprom_wbit <<= 1;
				}
				eeprom_rbit = 0x00;
		        } else if( eeprom_cmd[3] == 0x00 && eeprom_cmd[2] == 0x40
				&& eeprom_cmd[1] == 0x60 && eeprom_cmd[0] == 0x40 && data == 0x00 ) {
			// write 1
				eeprom_data |= eeprom_wbit;
				if( eeprom_wbit == 0x80 ) {
					if( eeprom_mode ) {
						WRAM[eeprom_addr] = eeprom_data;
					} else {
//						eeprom_addr = (eeprom_addr+1) & 0x7F;
						eeprom_addr = eeprom_data & 0x7F;
					}
					eeprom_wbit = 0x00;
				} else {
					eeprom_wbit <<= 1;
				}
				eeprom_rbit = 0x00;
			}
			eeprom_cmd[3] = eeprom_cmd[2];
			eeprom_cmd[2] = eeprom_cmd[1];
			eeprom_cmd[1] = eeprom_cmd[0];
			eeprom_cmd[0] = data;
			break;
	}
}

// Famicom Jump 2
void	Mapper016::WriteSubB( WORD addr, BYTE data )
{
	switch( addr ) {
		case	0x8000:
		case	0x8001:
		case	0x8002:
		case	0x8003:
			reg[0] = data & 0x01;
			SetPROM_8K_Bank( 4, reg[0]*0x20+reg[2]*2+0 );
			SetPROM_8K_Bank( 5, reg[0]*0x20+reg[2]*2+1 );
			break;
		case	0x8004:
		case	0x8005:
		case	0x8006:
		case	0x8007:
			reg[1] = data & 0x01;
			SetPROM_8K_Bank( 6, reg[1]*0x20+0x1E );
			SetPROM_8K_Bank( 7, reg[1]*0x20+0x1F );
			break;
		case	0x8008:
			reg[2] = data;
			SetPROM_8K_Bank( 4, reg[0]*0x20+reg[2]*2+0 );
			SetPROM_8K_Bank( 5, reg[0]*0x20+reg[2]*2+1 );
			SetPROM_8K_Bank( 6, reg[1]*0x20+0x1E );
			SetPROM_8K_Bank( 7, reg[1]*0x20+0x1F );
			break;

		case	0x8009:
			data &= 0x03;
			if( data == 0 )	     SetVRAM_Mirror( VRAM_VMIRROR );
			else if( data == 1 ) SetVRAM_Mirror( VRAM_HMIRROR );
			else if( data == 2 ) SetVRAM_Mirror( VRAM_MIRROR4L );
			else		     SetVRAM_Mirror( VRAM_MIRROR4H );
			break;

		case	0x800A:
			irq_enable = data & 0x01;
			irq_counter = irq_latch;
			break;
		case	0x800B:
			irq_latch = (irq_latch & 0xFF00) | data;
			break;
		case	0x800C:
			irq_latch = ((INT)data << 8) | (irq_latch & 0x00FF);
			break;

		case	0x800D:
			break;
	}
}

void	Mapper016::HSync( INT scanline )
{
	if( irq_type != 0 && irq_enable ) {
		if( irq_counter <= 113 ) {
			nes->cpu->IRQ();
//			nes->cpu->IRQ_NotPending();
			irq_enable = 0;
			irq_counter = 0;
		} else {
			irq_counter -= 113;
		}
	}
}

void	Mapper016::Clock( INT cycles )
{
	if( irq_type == 0 && irq_enable ) {
		if( (irq_counter-=cycles) <= 0 ) {
			nes->cpu->IRQ();
//			nes->cpu->IRQ_NotPending();
			irq_enable = 0;
			irq_counter = 0;
		}
	}
}

void	Mapper016::SaveState( LPBYTE p )
{
	p[0] = reg[0];
	p[1] = reg[1];
	p[2] = reg[2];
	p[3] = irq_enable;
	*(INT*)&p[4] = irq_counter;
	*(INT*)&p[8] = irq_latch;

	p[12] = eeprom_stat;
	p[13] = eeprom_mode;
	p[14] = eeprom_addr;
	p[15] = eeprom_data;
	p[16] = eeprom_wbit;
	p[17] = eeprom_rbit;
	p[18] = eeprom_cmd[0];
	p[19] = eeprom_cmd[1];
	p[20] = eeprom_cmd[2];
	p[21] = eeprom_cmd[3];
}

void	Mapper016::LoadState( LPBYTE p )
{
	reg[0] = p[0];
	reg[1] = p[1];
	reg[2] = p[2];
	irq_enable  = p[3];
	irq_counter = *(INT*)&p[4];
	irq_latch   = *(INT*)&p[8];

	eeprom_stat = p[12];
	eeprom_mode = p[13];
	eeprom_addr = p[14];
	eeprom_data = p[15];
	eeprom_wbit = p[16];
	eeprom_rbit = p[17];
	eeprom_cmd[0] = p[18];
	eeprom_cmd[1] = p[19];
	eeprom_cmd[2] = p[20];
	eeprom_cmd[3] = p[21];
}
