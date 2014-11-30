#include "GameBoard.h"

class ChessPiece : public GamePiece {};

void processGameBoard(const GameBoard board)
{
  const GamePiece& pawn = board.getPieceAt(0, 0);

  // Doesn't compile
  //board.setPieceAt(1, 2, pawn);
}

int main()
{
  GameBoard chessBoard(10, 10);
  ChessPiece pawn;

  chessBoard.setPieceAt(0, 0, pawn);
  chessBoard.setPieceAt(0, 1, chessBoard.getPieceAt(0, 0));

  GameBoard board2;
  board2 = chessBoard;

  processGameBoard(board2);

  return 0;
}
