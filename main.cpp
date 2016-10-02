#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int askRange(int);
int getMagicNumber(int, int);
void goGuess(int, int);

int main()
{
    cout << "***** GUESSING GAME PROGRAM *****\n" << endl;
    int numRange, theMagicNum, range, tmn;
    numRange = askRange(range);
    theMagicNum = getMagicNumber(tmn,numRange);
    goGuess(theMagicNum,numRange);

    return 0;
}

// Ask range.
int askRange(int theRange)
{
    do
    {
        cout << "What do you want the range of numbers to be?\n(Must be 10 or greater) ";
        cin >> theRange;
    }
    while( theRange < 10);
    return theRange;
}

//Generate the random number
int getMagicNumber(int num1, int rng)
    {
    time_t seconds;
    seconds = time (NULL);
    srand(seconds);
    num1 = rand() % rng;
    return num1;
    }

void goGuess(int tmn, int numR)
    {
        int guess, numTries;
        numTries = 0;
    do
    {
        cout << "OK - I am thinking of a number between 0 and " << numR << ".\n";
        cout << "What is your guess? ";
        cin >> guess;
        if( guess == tmn)
        {
            cout << "\nCONGRATULATIONS !!!!!!!  YOU GUESSED IT.\n";
            numTries = 6;
            return;
        }
        else if( guess > tmn)
        {
            cout << "\nYour guess is higher than the magic number.\n";
            numTries = numTries + 1;
        }
        else if(guess < tmn)
        {
            cout << "\nYour guess is lower than the magic number.\n";
            numTries = numTries + 1;
        }
    }
        while( numTries < 5);

    cout << "\n\nYou ran out of guesses.  Sorry.  The magic Number was: " << tmn << endl;
        return;
    }

