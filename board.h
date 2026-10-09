#pragma once
#include "pieces.h"
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

enum Turn{
    WHITE,
    BLACK
};

class Board{
    private:
        unique_ptr<Piece> grid[8][8];
        pair<int,int> kingPosition(Turn turn);
    public:
        Turn currentTurn = Turn::WHITE;

        void cleanBoard();
        void setBoard();
        void showBoard();
        void movePiece(int startX, int startY, int endX, int endY);
        bool isPathClear(int startX, int startY, int endX, int endY);
        bool isCheck(Turn turn);
        bool simulateMoveandCheck(int startX, int startY, int endX, int endY);
};

