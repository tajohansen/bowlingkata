//
// Created by troyjohansen on 12/12/2018.
//

#include "Game.h"




void Game::roll(int frame)
{
    rolls[currentRoll] = frame;
    currentRoll++;


}

int Game::scoreGame()
{
    int score = 0;
    int rollNum = 0;
    for(int frame = 0; frame < 10; frame++)
    {
        if (isStrike(rollNum))
        {
            
        }
        if (rolls[frame] == 10)
        {
            score += rolls[rollNum] + rolls[rollNum + 1] + rolls[rollNum + 2];
            rollNum += 1;
        }
        else if (isSpare(rollNum)) // Spare
        {
            score += 10 + rolls[rollNum + 2];
            rollNum += 2;
        }
        else
        {
            score += rolls[rollNum] + rolls[rollNum+1];
            rollNum += 2;
        }
    }

    return score;
}

bool Game::isSpare(int frameIndex)
{
    return (rolls[frameIndex] + rolls[frameIndex + 1]) == 10 ;
}

Game::Game(){
    currentRoll = 0;
    rolls.fill(0);
}

bool Game::isStrike(int frameIndex)
{
    return rolls[frameIndex] == 10;
}
