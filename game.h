#pragma once
#include <iostream>
using namespace std;

class Game{
    private:
        bool isEnded = false;
    public:

        bool isGameEnded(){
            return isEnded;
        }

        void startGame();
        int letterToInt(char letter);
        int numToInt(char letter);
};

