//////////////////////////////////////////////////////////////////////////
// Mapper068  SunSoft Mapper 4 (After Burner II)                        //
//////////////////////////////////////////////////////////////////////////
class	Mapper068 : public Mapper
{
public:
	Mapper068( NES* parent ) : Mapper(parent) {}

	void	Reset();
	void	Write(WORD addr, BYTE data);

	// For state save
	BOOL	IsStateSave() { return TRUE; }
	void	SaveState( LPBYTE p );
	void	LoadState( LPBYTE p );

protected:
	BYTE	reg[4];
private:
	void	SetBank();
};
