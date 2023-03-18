#include "Pig_Game_Header.h"

void PigGame(void)
{

}
void displayDiceRollValue(int x)
{
    if (x == 0)
    {
        cout << "Roll = 1\n"; 
    } 
    else if (x == 1)
    {
        cout << "Hold = 0\n"; 
    }
    else 
    {
        cout << endl; 
    }
}
void displayScore(int x)
{
    cout << "Score = " << x << endl;
}
int rollDice(void)
{
    Sleep(SleepTime); 
    srand(time(NULL)); 
    int diceValue = rand() % 6 + 1; 
    return diceValue; 
}
int getDiceValue(int x)
{
    switch(x)
    {
        case 1:
        {
            return ONE; 
            break; 
        }
        case 2: 
        {
            return TWO; 
            break; 
        }
        case 3: 
        {
            return THREE; 
            break;
        }
        case 4:
        {
            return FOUR;
            break; 
        }
        case 5: 
        {
            return FIVE; 
            break; 
        }
        case 6:
        {
            return SIX; 
            break; 
        }
        default:
        {
            break; 
        }
    }
}
int humanTurn(int humanTotalScore)
{
    /**
     * @brief can either roll or hold 
     * if roll - if roll a one during any roll - score remains the same
     * and switch to computer turn 
     * else, if roll - keep adding the scores until human score (x >= 100) 
     * if hold, then switch to computer 
     * 
     */
    
}
int computerTurn(int computerTotalScore)
{
    /**
     * @brief computer always roll until they hit a one, 
     * swich to human
     * otherwise, keep rolling until computer score is 20 or higher (x >= 20)
     * 
     */

}
int getRollOrHold (int humanScore, int computerScore)
{
    char rollOrHold = '/0';
    int tempScore = 0; 
    cout << "Enter r/R or h/H: "; 
    cin >> rollOrHold; 
    if (rollOrHold == 'h' || rollOrHold == 'H')
    {
        computerScore = computerTurn(computerScore); 
        return tempScore; 
    }
    else if (rollOrHold == 'r' || rollOrHold == 'R')
    {
        humanScore = humanTurn(humanScore); 
        return tempScore + humanScore; 
    }
    else 
    {
        cout << "Wrong option, try again.\n"; 
        getRollOrHold(humanScore,computerScore);
    }
}
int getTurnsCount(int x)
{
    return x; 
}
int incrementTurnsCount(int x)
{
    int turnsCount = setTurnsCount(x) + 1; 
    return turnsCount;
}
int setTurnsCount(int x)
{
    return x; 
}
int main(int argc, char ** argv)
{
    PigGame(); 
    return 0;
}