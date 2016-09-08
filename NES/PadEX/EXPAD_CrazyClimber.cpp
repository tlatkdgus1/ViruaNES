//////////////////////////////////////////////////////////////////////////
// Crazy climber                                                        //
//////////////////////////////////////////////////////////////////////////
void	EXPAD_CrazyClimber::Strobe()
{
	nes->pad->pad1bit &= ~0xF0;
	nes->pad->pad1bit |=  bits & 0xF0;
	nes->pad->pad2bit &= ~0xF0;
	nes->pad->pad2bit |= (bits & 0x0F)<<4;
}

void	EXPAD_CrazyClimber::Sync()
{
	bits = 0;

	if( DirectInput.m_Sw[Config.controller.nExButton[0][0]] || DirectInput.m_Sw[Config.controller.nExButton[0][10]] )
		bits |= 1<<6;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][1]] || DirectInput.m_Sw[Config.controller.nExButton[0][11]] )
		bits |= 1<<7;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][2]] || DirectInput.m_Sw[Config.controller.nExButton[0][12]] )
		bits |= 1<<5;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][3]] || DirectInput.m_Sw[Config.controller.nExButton[0][13]] )
		bits |= 1<<4;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][4]] || DirectInput.m_Sw[Config.controller.nExButton[0][14]] )
		bits |= 1<<2;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][5]] || DirectInput.m_Sw[Config.controller.nExButton[0][15]] )
		bits |= 1<<3;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][6]] || DirectInput.m_Sw[Config.controller.nExButton[0][16]] )
		bits |= 1<<1;
	if( DirectInput.m_Sw[Config.controller.nExButton[0][7]] || DirectInput.m_Sw[Config.controller.nExButton[0][17]] )
		bits |= 1<<0;

	// “¯“ü—Í‚ğ‹Ö~‚·‚é
	if( (bits&((1<<0)|(1<<1))) == ((1<<0)|(1<<1)) )
		bits &= ~((1<<0)|(1<<1));
	if( (bits&((1<<2)|(1<<3))) == ((1<<2)|(1<<3)) )
		bits &= ~((1<<2)|(1<<3));
	if( (bits&((1<<4)|(1<<5))) == ((1<<4)|(1<<5)) )
		bits &= ~((1<<4)|(1<<5));
	if( (bits&((1<<6)|(1<<7))) == ((1<<6)|(1<<7)) )
		bits &= ~((1<<6)|(1<<7));
}

void	EXPAD_CrazyClimber::SetSyncData( INT type, LONG data )
{
	bits = (BYTE)data;
}

LONG	EXPAD_CrazyClimber::GetSyncData( INT type )
{
	return	bits;
}

