#include <iostream>
#include <string>
#include "board.h"
#include "pieces.h"
#include <utility>
using namespace std;


void Board:: cleanBoard(){
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8 ; j ++){
            Board::grid[i][j] = nullptr;
        }
    }
}

void Board:: setBoard(){
    for (int i = 0; i < 8; i++){
        grid[1][i] = make_unique<Pawn>(PieceColor::WHITE);
        grid[6][i] = make_unique<Pawn>(PieceColor::BLACK);    
    }

    // white pieces
    grid[0][0] = make_unique<Rook>(PieceColor::WHITE);
    grid[0][1] = make_unique<Knight>(PieceColor::WHITE);
    grid[0][2] = make_unique<Bishop>(PieceColor::WHITE);
    grid[0][3] = make_unique<Queen>(PieceColor::WHITE);
    grid[0][4] = make_unique<King>(PieceColor::WHITE);
    grid[0][5] = make_unique<Bishop>(PieceColor::WHITE);
    grid[0][6] = make_unique<Knight>(PieceColor::WHITE);
    grid[0][7] = make_unique<Rook>(PieceColor::WHITE);


    //black pieces
    grid[7][0] = make_unique<Rook>(PieceColor::BLACK);
    grid[7][1] = make_unique<Knight>(PieceColor::BLACK);
    grid[7][2] = make_unique<Bishop>(PieceColor::BLACK);
    grid[7][3] = make_unique<Queen>(PieceColor::BLACK);
    grid[7][4] = make_unique<King>(PieceColor::BLACK);
    grid[7][5] = make_unique<Bishop>(PieceColor::BLACK);
    grid[7][6] = make_unique<Knight>(PieceColor::BLACK);
    grid[7][7] = make_unique<Rook>(PieceColor::BLACK);

}

void Board::showBoard(){
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j<8; j ++){
            if (grid[i][j] != nullptr){
                cout << grid[i][j]-> getSymbol() << ' ';
            }
            else{ 
                cout << ". ";
            } 
        }
        cout << endl;
    }
        
}

void Board::movePiece(int startX,int startY,int endX,int endY){
    if (grid[startX][startY]!= nullptr){
        Piece * piece = grid[endX][endY].get();

        if (grid[startX][startY] ->isValidMove(startX,startY,endX,endY,piece)){
            if (grid[startX][startY]->getSymbol() == 'N'|| grid[startX][startY]->getSymbol() == 'n'){
                grid[endX][endY] = std::move(grid[startX][startY]);
            }
            else{
                if (Board::isPathClear(startX,startY,endX,endY)){
                    grid[endX][endY] = std::move(grid[startX][startY]);
                }
            }
        }
    }
}

bool Board::isPathClear(int startX,int startY,int endX,int endY){
    int dirX,dirY;
    if (endX>startX) dirX = 1;
    else if (endX<startX) dirX = -1;
    else dirX = 0;

    if (endY>startY) dirY = 1;
    else if (endY<startY) dirY = -1;
    else dirY = 0;

    int currentX = startX + dirX;
    int currentY = startY + dirY;

    while((currentX != endX)||(currentY != endY)){
        if (grid[currentX][currentY] != nullptr) return false;
        currentX += dirX;
        currentY += dirY;
        
    }
    return true;
}

pair<int,int> Board::kingPosition(Turn turn){
    char symbol = (turn == WHITE)?'K':'k';

    for(int y = 0; y < 8; y ++){
        for (int x = 0; x<8; x++){
            if (Board::grid[x][y] -> getSymbol() == symbol) return make_pair(x,y);
        }
}
}

bool Board::isCheck(Turn turn){
    auto kingPos = kingPosition(turn);
    int kingX = kingPos.first;
    int kingY = kingPos.second;
    Piece * kingPiece  = grid[kingX][kingY].get();

    PieceColor enemyColor;
    if (turn == WHITE) enemyColor = PieceColor::BLACK;
    else enemyColor = PieceColor::WHITE;

    for(int y = 0; y < 8; y ++){
        for (int x = 0; x<8; x++){
            if (grid[x][y] != nullptr  && grid[x][y] -> getColor() == enemyColor){
                if (grid[x][y] -> isValidMove(x,y,kingX,kingY,kingPiece)) return true;
                }
        }
    } 
    return false;
}