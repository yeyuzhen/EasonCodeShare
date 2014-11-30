#include "GameBoard.h"

class ChessPiece : public GamePiece
{
public:
	virtual ChessPiece* Clone() const
	{
		auto clone = new ChessPiece();
		// Copy all ChessPiece specific data to the clone, and return the result.
		return clone;
	}
};

void processGameBoard(const GameBoard& board)
{
	const GamePiece* pawn = board.getPieceAt(0, 0);

	// Doesn't compile
	//board.setPieceAt(1, 2, pawn);
}

int main()
{
	GameBoard chessBoard(8, 8);
	ChessPiece pawn;

	chessBoard.setPieceAt(0, 0, &pawn);
	chessBoard.setPieceAt(0, 1, chessBoard.getPieceAt(0, 0));

	GameBoard board2;
	board2 = chessBoard;

	processGameBoard(board2);

	return 0;
}
