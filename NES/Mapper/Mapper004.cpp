//////////////////////////////////////////////////////////////////////////
// Mapper004  Nintendo MMC3                                             //
//////////////////////////////////////////////////////////////////////////
#define	MMC3_IRQ_REQUESTCLOCK	(1<<0)
#define	MMC3_IRQ_REQUESTHSYNC	0
#define	MMC3_IRQ_PREDEC		(1<<1)
#define	MMC3_IRQ_WARWOLF	(1<<7)
#define	MMC3_IRQ_FF3		(1<<6)
#define	MMC3_IRQ_METAL		(1<<5)

void	Mapper004::Reset()
{
	for( INT i = 0; i < 8; i++ ) {
		reg[i] = 0x00;
	}

	prg0 = 0;
	prg1 = 1;
	SetBank_CPU();

	chr01 = 0;
	chr23 = 2;
	chr4  = 4;
	chr5  = 5;
	chr6  = 6;
	chr7  = 7;
	SetBank_PPU();

	we_sram  = 0;	// Disable
	irq_enable = 0;	// Disable
	irq_counter = 0;
	irq_latch = 0;
	irq_request = 0;

	irq_type = MMC3_IRQ_REQUESTCLOCK|MMC3_IRQ_PREDEC;

	DWORD	crc = nes->rom->GetPROM_CRC();

	if( crc == 0x5c707ac4 ) {	// Mother(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_PREDEC;
		nes->SetRenderMethod( NES::TILE_RENDER );
	}

	if( crc == 0xade11141		// Wanpaku Kokkun no Gourmet World(J)
	 || crc == 0x6cc62c06		// Hoshi no Kirby - Yume no Izumi no Monogatari(J)
	 || crc == 0xc17ae2dc ) {	// God Slayer - Haruka Tenkuu no Sonata(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_PREDEC;
		nes->SetRenderMethod( NES::TILE_RENDER );
	}

	if( crc == 0xeffeea40 ) {	// For Klax(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC;
		nes->SetRenderMethod( NES::TILE_RENDER );
	}
	if( crc == 0xd7a97b38 ) {	// Chou Jinrou Senki - Warwolf(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_WARWOLF;
	}
	if( crc == 0x4fb460cd ) {	// Nekketsu! Street Basket - Ganbare Dunk Heroes(J)
		irq_type = MMC3_IRQ_REQUESTCLOCK;
	}
	if( crc == 0x5a6860f1		// Shougi Meikan '92(J)
	 || crc == 0xae280e20 ) {	// Shougi Meikan '93(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC;
	}
	if( crc == 0x0bf31a3d ) {	// Soreike! Anpanman - Minna de Hiking Game!(J)
		nes->SetRenderMethod( NES::POST_RENDER );
	}
	if( crc == 0x877dba77 ) {	// My Life My Love - Boku no Yume - Watashi no Negai(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_PREDEC;
	}
	if( crc == 0x1170392a ) {	// Karakuri Kengou Den - Musashi Road - Karakuri Nin Hashiru!(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_PREDEC;
	}
	if( crc == 0xcb106f49 ) {	// F-1 Sensation(J)
		nes->SetRenderMethod( NES::TILE_RENDER );
	}
	if( crc == 0x57e220d0 ) {	// Final Fantasy III(J)
		irq_type = MMC3_IRQ_REQUESTCLOCK|MMC3_IRQ_FF3;
	}
	if( crc == 0x817cfa97 ) {	// Kyouryuu Sentai Juuranger(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_PREDEC;
	}
	if( crc == 0xE386DA54 ) {	// SuperMarioBros3(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_PREDEC;
	}
	if( crc == 0x7c7ab58e ) {	// Walkuere no Bouken - Toki no Kagi Densetsu(J)
		nes->SetRenderMethod( NES::POST_RENDER );
	}
	if( crc == 0xd88d48d7 ) { 	// Kick Master(U)
		nes->SetRenderMethod( NES::TILE_RENDER );
		irq_type = MMC3_IRQ_REQUESTHSYNC;
	}
	if( crc == 0xfd0299c3 ) {	// METAL MAX(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC|MMC3_IRQ_METAL;
	}
	if( crc == 0x13ec1c90 ) {	// Genpei Touma Den - Computer Boardgame(J)
		irq_type = MMC3_IRQ_REQUESTHSYNC;
	}
	if( crc == 0xaafe699c ) {	// Ninja Ryukenden 3 - Yomi no Hakobune(J)
		nes->SetRenderMethod( NES::TILE_RENDER );
	}
}

void	Mapper004::Write( WORD addr, BYTE data )
{
//DEBUGOUT( "MPRWR A=%04X D=%02X L=%3d CYC=%d\n", addr&0xFFFF, data&0xFF, nes->GetScanline(), nes->cpu->GetTotalCycles() );

	switch( addr & 0xE001 ) {
		case	0x8000:
			reg[0] = data;
			SetBank_CPU();
			SetBank_PPU();
			break;
		case	0x8001:
			reg[1] = data;

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
				case	0x06:
					prg0 = data;
					SetBank_CPU();
					break;
				case	0x07:
					prg1 = data;
					SetBank_CPU();
					break;
			}
			break;
		case	0xA000:
			reg[2] = data;
			if( !nes->rom->Is4SCREEN() ) {
				if( data & 0x01 ) SetVRAM_Mirror( VRAM_HMIRROR );
				else		  SetVRAM_Mirror( VRAM_VMIRROR );
			}
			break;
		case	0xA001:
			reg[3] = data;
			break;
		case	0xC000:
			reg[4] = data;
			irq_counter = data;
			irq_request = 0;
			break;
		case	0xC001:
			reg[5] = data;
			irq_latch = data;
			irq_request = 0;
			break;
		case	0xE000:
			reg[6] = data;
			irq_enable = 0;
			irq_request = 0;
			break;
		case	0xE001:
			reg[7] = data;
			irq_enable = 1;
			irq_request = 0;
			break;
	}
}

void	Mapper004::Clock( INT cycles )
{
	if( irq_request && (irq_type&MMC3_IRQ_REQUESTCLOCK) ) {
		nes->cpu->IRQ_NotPending();
	}
}

void	Mapper004::HSync( INT scanline )
{
	if( (scanline >= 0 && scanline <= 239) ) {
		if( nes->ppu->IsDispON() ) {
			if( irq_enable && !irq_request ) {
				if( scanline == 0 && (irq_type&MMC3_IRQ_PREDEC) ) {
					if( irq_counter ) {
						irq_counter--;
					}
				}
				if( !(irq_type&(MMC3_IRQ_WARWOLF|MMC3_IRQ_FF3|MMC3_IRQ_METAL)) ) {
					if( !(irq_counter--) ) {
						irq_request = 0xFF;
						irq_counter = irq_latch;
					}
				} else if( irq_type&MMC3_IRQ_FF3 ) {
					if( !(--irq_counter) ) {
						irq_request = 0xFF;
						irq_counter = irq_latch;
					}
				} else if( irq_type&MMC3_IRQ_METAL ) {
					if( !(irq_counter--) ) {
						irq_request = 0xFF;
						irq_counter = irq_latch;
#if	0
{
LPBYTE	lpScn = nes->ppu->GetScreenPtr();

	lpScn = lpScn+(256+16)*scanline;

	for( INT i = 0; i < 256+16; i++ ) {
		lpScn[i] = 22;
	}
}
#endif
					}
				} else {
					if( --irq_counter == 0x01 ) {
						irq_request = 0xFF;
						irq_counter = irq_latch;
					}
				}
			}
		}
	}
	if( irq_request && !(irq_type&MMC3_IRQ_REQUESTCLOCK) ) {
		nes->cpu->IRQ_NotPending();
	}
}

void	Mapper004::SetBank_CPU()
{
	if( reg[0] & 0x40 ) {
		SetPROM_32K_Bank( PROM_8K_SIZE-2, prg1, prg0, PROM_8K_SIZE-1 );
	} else {
		SetPROM_32K_Bank( prg0, prg1, PROM_8K_SIZE-2, PROM_8K_SIZE-1 );
	}
}

void	Mapper004::SetBank_PPU()
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

void	Mapper004::SaveState( LPBYTE p )
{
	for( INT i = 0; i < 8; i++ ) {
		p[i] = reg[i];
	}
	p[ 8] = prg0;
	p[ 9] = prg1;
	p[10] = chr01;
	p[11] = chr23;
	p[12] = chr4;
	p[13] = chr5;
	p[14] = chr6;
	p[15] = chr7;
	p[16] = irq_enable;
	p[17] = (BYTE)irq_counter;
	p[18] = irq_latch;
	p[19] = irq_request;
}

void	Mapper004::LoadState( LPBYTE p )
{
	for( INT i = 0; i < 8; i++ ) {
		reg[i] = p[i];
	}
	prg0  = p[ 8];
	prg1  = p[ 9];
	chr01 = p[10];
	chr23 = p[11];
	chr4  = p[12];
	chr5  = p[13];
	chr6  = p[14];
	chr7  = p[15];
	irq_enable  = p[16];
	irq_counter = (INT)p[17];
	irq_latch   = p[18];
	irq_request = p[19];
}
