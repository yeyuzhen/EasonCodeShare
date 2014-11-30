// GameBoard.h

class GamePiece
{
public:
	virtual GamePiece* Clone() const
	{
		return new GamePiece();
	}
};

class GameBoard
{
public:
	// The general-purpose GameBoard allows the user to specify its dimensions
	GameBoard(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	GameBoard(const GameBoard& src); // copy constructor
	virtual ~GameBoard();
	GameBoard& operator=(const GameBoard& rhs); // assignment operator

	void setPieceAt(size_t x, size_t y, const GamePiece* inPiece);
	GamePiece* getPieceAt(size_t x, size_t y);
	const GamePiece* getPieceAt(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

protected:
	void copyFrom(const GameBoard& src);
	void initializeCells();
	void cleanupCells();
	// objects dynamically allocate space for the game pieces.
	GamePiece*** mCells;
	size_t mWidth, mHeight;
};
