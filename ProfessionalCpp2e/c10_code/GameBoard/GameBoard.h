#include <stdexcept>
#include <new>
using std::bad_alloc;
using std::out_of_range;

class GamePiece {};

class GameBoard
{
 public:
  // general-purpose GameBoard allows user to specify its dimensions
  GameBoard(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight)
    throw(bad_alloc);
  GameBoard(const GameBoard& src) throw(bad_alloc); // Copy constructor
  virtual ~GameBoard() noexcept;

  GameBoard& operator=(const GameBoard& rhs) throw(bad_alloc); // Assignment operator

  void setPieceAt(int x, int y, const GamePiece& inPiece)
    throw(out_of_range);
  GamePiece& getPieceAt(int x, int y) throw(out_of_range);
  const GamePiece& getPieceAt(int x, int y) const throw(out_of_range);

  int getHeight() const noexcept { return mHeight; }
  int getWidth() const noexcept { return mWidth; }


  static const int kDefaultWidth = 100;
  static const int kDefaultHeight = 100;

 protected:
  void copyFrom(const GameBoard& src) throw(bad_alloc);

  // Objects dynamically allocate space for the game pieces.
  GamePiece** mCells;
  int mWidth, mHeight;
};
