//
// ROMヘッダの修正(NESToyでの間違い修正など)及びROMパッチ
//

// Mapper 000
if( crc == 0x57970078 ) {	// F-1 Race(J) 無理矢理パッチ(^^;
	lpPRG[0x078C] = 0x6C;
//	lpPRG[0x3F97] = 0x7F;	// 失敗…
	lpPRG[0x3FE1] = 0xFF;
	lpPRG[0x3FE6] = 0x00;
}
if( crc == 0xaf2bbcbc		// Mach Rider(JU)
 || crc == 0x3acd4bf1 ) {	// Mach Rider(Alt)(JU) 無理矢理パッチ(^^;
	lpPRG[0x090D] = 0x6E;
//	lpPRG[0x7F95] = 0x7F;	// 失敗…
	lpPRG[0x7FDF] = 0xFF;
	lpPRG[0x7FE4] = 0x00;
}
if( crc == 0xe16bb5fe ) {	// Zippy Race(J)
	header.control1 &= 0xf6;
}

// Mapper 001
if( crc == 0x7831b2ff		// America Daitouryou Senkyo(J)
 || crc == 0x190a3e11		// Be-Bop-Highschool - Koukousei Gokuraku Densetsu(J)
 || crc == 0x52449508		// Home Run Nighter - Pennant League!!(J)
 || crc == 0x0973f714		// Jangou(J)
 || crc == 0x7172f3d4		// Kabushiki Doujou(J)
 || crc == 0xa5781280		// Kujaku Ou 2(J)
 || crc == 0x8ce9c87b		// Money Game, The(J)
 || crc == 0xec47296d		// Morita Kazuo no Shougi(J)
 || crc == 0xcee5857b		// Ninjara Hoi!(J)
 || crc == 0xe63d9193		// Tanigawa Kouji no Shougi Shinan 3(J)
 || crc == 0xd54f5da9 ) {	// Tsuppari Wars(J)
	header.control1 |= ROM_SAVERAM;
}
if( crc == 0x1995ac4e ) {	// Ferrari Grand Prix Challenge(J) 無理矢理パッチ(^^;
	lpPRG[0x1F7AD] = 0xFF;
	lpPRG[0x1F7BC] = 0x00;
}

if( crc == 0x20d22251 ) {	// Top rider(J) 無理矢理パッチ(^^;
	lpPRG[0x1F17E] = 0xEA;
	lpPRG[0x1F17F] = 0xEA;
}

if( crc == 0x11469ce3 ) {	// Viva! Las Vegas(J) 無理矢理パッチ(^^;
	lpCHR[0x0000] = 0x01;
}

// Mapper 002
if( crc == 0x63af202f ) {	// JJ - Tobidase Daisakusen Part 2(J)
	header.control1 &= 0xf6;
	header.control1 |= ROM_VMIRROR;
}

if( crc == 0x99a62e47 ) {	// Black Bass 2, The(J)
	header.control1 &= 0xf6;
	header.control1 |= ROM_VMIRROR;
}

// Mapper 003
if( crc == 0x29401686 ) {	// Minna no Taabou no Nakayoshi Dai Sakusen(J)
//	lpPRG[0x2B3E] = 0x60;
}
if( crc == 0x932a077a ) {	// TwinBee(J)
	mapper = 87;
}
if( crc == 0x8218c637 ) {	// Space Hunter(J)
	header.control1 &= 0xf6;
	header.control1 |= ROM_4SCREEN;
}
if( crc == 0x2bb6a0f8		// Sherlock Holmes - Hakushaku Reijou Yuukai Jiken(J)
 || crc == 0x28c11d24		// Sukeban Deka 3(J)
 || crc == 0x02863604 ) {	// Sukeban Deka 3(J)(Alt)
	header.control1 &= 0xf6;
	header.control1 |= ROM_VMIRROR;
}

// Mapper 004
if( crc == 0x58581770) {	// Rasaaru Ishii no Childs Quest(J)
	header.control1 &= 0xf6;
	header.control1 |= ROM_VMIRROR;
}
if( crc == 0xf3feb3ab		// Kunio Kun no Jidaigeki Dayo Zenin Shuugou! (J)
 || crc == 0xa524ae9b		// Otaku no Seiza - An Adventure in the Otaku Galaxy (J)
 || crc == 0x46dc6e57		// SD Gundam - Gachapon Senshi 2 - Capsule Senki (J)
 || crc == 0x66b2dec7		// SD Gundam - Gachapon Senshi 3 - Eiyuu Senki (J)
 || crc == 0x92b07fd9		// SD Gundam - Gachapon Senshi 4 - New Type Story (J)
 || crc == 0x8ee6463a		// SD Gundam - Gachapon Senshi 5 - Battle of Universal Century (J)
 || crc == 0xaf754426		// Ultraman Club 3 (J)
 || crc == 0xfe4e5b11		// Ushio to Tora - Shinen no Daiyou (J)
 || crc == 0x57c12c17 ) {	// Yamamura Misa Suspense - Kyouto Zaiteku Satsujin Jiken (J)
	header.control1 |= ROM_SAVERAM;
}
if( crc == 0x42e03e4a ) {	// RPG Jinsei Game (J)
	mapper = 118;
	header.control1 |= ROM_SAVERAM;
}
if( crc == 0xfd0299c3 ) {	// METAL MAX(J)
	lpPRG[0x3D522] = 0xA9;
	lpPRG[0x3D523] = 0x19;
}

// Mapper 005
if( crc == 0xe91548d8 ) {	// Shin 4 Nin Uchi Mahjong - Yakuman Tengoku (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 010
if( crc == 0xc9cce8f2 ) {	// Famicom Wars (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 016
if( crc == 0x983d8175		// Datach - Battle Rush - Build Up Robot Tournament (J)
 || crc == 0x894efdbc		// Datach - Crayon Shin Chan - Ora to Poi Poi (J)
 || crc == 0x19e81461		// Datach - Dragon Ball Z - Gekitou Tenkaichi Budou Kai (J)
 || crc == 0xbe06853f		// Datach - J League Super Top Players (J)
 || crc == 0x0be0a328		// Datach - SD Gundam - Gundam Wars (J)
 || crc == 0x5b457641		// Datach - Ultraman Club - Supokon Fight! (J)
 || crc == 0xf51a7f46		// Datach - Yuu Yuu Hakusho - Bakutou Ankoku Bujutsu Kai (J)
 || crc == 0x31cd9903		// Dragon Ball Z - Kyoushuu! Saiya Jin (J)
 || crc == 0xe49fc53e		// Dragon Ball Z 2 - Gekishin Freeza!! (J)
 || crc == 0x09499f4d		// Dragon Ball Z 3 - Ressen Jinzou Ningen (J)
 || crc == 0x2e991109 ) {	// Dragon Ball Z Gaiden - Saiya Jin Zetsumetsu Keikaku (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 019
if( crc == 0x3296ff7a		// Battle Fleet (J)
 || crc == 0x429fd177		// Famista '90 (J)
 || crc == 0xdd454208		// Hydlide 3 - Yami Kara no Houmonsha (J)
 || crc == 0xb1b9e187		// Kaijuu Monogatari (J)
 || crc == 0xaf15338f ) {	// Mindseeker (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 026
if( crc == 0x836cc1ab ) {	// Mouryou Senki Madara (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 033
if( crc == 0x547e6cc1 ) {	// Flintstones - The Rescue of Dino & Hoppy, The(J)
	mapper = 48;
}

// Mapper 065
if( crc == 0xfd3fc292 ) {	// Ai Sensei no Oshiete - Watashi no Hoshi (J)
	mapper = 32;
}

// Mapper 068
if( crc == 0xfde79681 ) {	// Maharaja (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 082
if( crc == 0x4819a595 ) {	// Kyuukyoku Harikiri Stadium - Heisei Gannen Ban (J)
	header.control1 |= ROM_SAVERAM;
}

// Mapper 086
if( crc == 0xe63f7d0b ) {	// Urusei Yatsura - Lum no Wedding Bell(J)
	mapper = 101;
}

// Mapper 180
if( crc == 0xc68363f6 ) {	// Crazy Climber(J)
	header.control1 &= 0xf6;
}

