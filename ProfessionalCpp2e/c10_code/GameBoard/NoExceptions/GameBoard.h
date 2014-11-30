class GamePiece {};

class GameBoard
{
 public:
  // general-purpose GameBoard allows user to specify its dimensions
  GameBoard(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
  GameBoard(const GameBoard& src); // Copy constructor
  virtual ~GameBoard();

  GameBoard& operator=(const GameBoard& rhs); // Assignment operator

  void setPieceAt(int x, int y, const GamePiece& inPiece);
  GamePiece& getPieceAt(int x, int y);
  const GamePiece& getPieceAt(int x, int y) const;

  int getHeight() const { return mHeight; }
  int getWidth() const { return mWidth; }


  static const int kDefaultWidth = 100;
  static const int kDefaultHeight = 100;

 protected:
  void copyFrom(const GameBoard& src);

  // Objects dynamically allocate space for the game pieces.
  GamePiece** mCells;
  int mWidth, mHeight;
};
