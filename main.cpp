#include "board.h"
#include "pieces.h"

using namespace std;

int main(){
    Board chessboard;

    chessboard.cleanBoard();
    chessboard.setBoard();
    chessboard.movePiece(1,2,3,2);
    chessboard.movePiece(6,5,5,5);
    chessboard.movePiece(1,7,2,7);
    chessboard.showBoard();

    return 0;
}