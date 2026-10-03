#include <iostream>
#include <string>
#include "game.h"
#include "board.h"

void Game::startGame(){
    bool isEnded = isGameEnded();
    Board chessboard;
    chessboard.cleanBoard();
    chessboard.setBoard();
    chessboard.showBoard();
    int moveNum = 0;
    string from,to;
    int x1,y1,x2,y2;

    while(!isEnded){
        cout<<"Enter move: ";
        if(moveNum %2 == 0){
            cout << "White:  ";
        }
        else{
            cout <<"Black:  ";
        }
        cin >> from >> to;
        cout <<endl;
        y1 = letterToInt(from[0]);
        x1= numToInt(from[1]);
        y2 = letterToInt(to[0]);
        x2= numToInt(to[1]);

        cout << "DEBUG: " << from << " okundu. X(satir): " << x1 << ", Y(sutun): " << y1 << endl;
        cout << "DEBUG: " << to << " okundu. X(satir): " << x2 << ", Y(sutun): " << y2 << endl;

        chessboard.movePiece(x1,y1,x2,y2);
        chessboard.showBoard();
        moveNum ++;

    }
}

int Game::letterToInt(char letter){
    return letter -'a';
}

int Game::numToInt(char letter){
    return (letter -'0')-1;
}