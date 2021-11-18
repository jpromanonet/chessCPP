#include <iostream>
#include "game.h"
#include "board.h"

/*
 * Main program for playing a chess game.
 */

int main (int argc, char * const argv[])
{
    Player* currentPlayer = NULL;

    // Initialise a chess game and display the initial state
    Game::initialise();
    Board::getBoard() -> display(cout);

    // Game loop in which players alternate making moves
    while(true)
    {
        currentPlayer = Game::getNextPlayer();
        while(!currentPlayer -> makeMove())
        {
            cerr << "Invalid move... Try again." << endl;
        }
        Board::getBoard() -> display(cout);
    }

    return 0;
}