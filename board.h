#pragma once
#include "pieces.h"
#include <iostream>
#include <memory>
using namespace std;


class Board{
    private:
        unique_ptr<Piece> grid[8][8];
    public:
        void cleanBoard();
        void setBoard();
        void showBoard();
        void movePiece(int startX, int startY, int endX, int endY);
        bool isPathClear(int startX, int startY, int endX, int endY);
};
