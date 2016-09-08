//////////////////////////////////////////////////////////////////////////
// Mapper016  Bandai Standard                                           //
//////////////////////////////////////////////////////////////////////////
class	Mapper016 : public Mapper
{
public:
	Mapper016( NES* parent ) : Mapper(parent) {}

	void	Reset();
	BYTE	ReadLow( WORD addr );
	void	WriteLow( WORD addr, BYTE data );
	void	Write( WORD addr, BYTE data );

	void	HSync( INT scanline );
	void	Clock( INT cycles );

	// For state save
	BOOL	IsStateSave() { return TRUE; }
	void	SaveState( LPBYTE p );
	void	LoadState( LPBYTE p );

protected:
	BYTE	patch;	// For Famicom Jump 2

	BYTE	reg[3];

	BYTE	irq_enable;
	INT	irq_counter;
	INT	irq_latch;
	BYTE	irq_type;

	BYTE	outport;

	BYTE	eeprom_cmd[4];
	BYTE	eeprom_stat;
	BYTE	eeprom_mode;
	BYTE	eeprom_addr, eeprom_data;
	BYTE	eeprom_wbit, eeprom_rbit;

private:
	void	WriteSubA(WORD addr, BYTE data);
	void	WriteSubB(WORD addr, BYTE data);
};
