#include "game.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "square.h"

Game::Game()
{
}

Game::~Game()
{
    // Delete pieces
    for (set<Piece*>::iterator itr = whitePieces.begin();
        itr != whitePieces.end(); ++itr)
    {
        delete *itr;
    }
    whitePieces.clear();
    for(set<Piece*>::iterator itr = blackPieces.begin();
        itr != blackPieces.end(); ++itr)
    {
        delete *itr;
    }
    blackPieces.clear();

    // Delete players
    delete &player1;
    delete &player2;
}

void Game::initialize()
{
    Piece* aPiece;
    King* aKing;
    Square* aSquare;

    // Create piece sets
    whitePieces = *(new set<Piece*>);
    blackPieces = *(new set<Piece*>);

    // Create each piece
    // Set their locations
    // Put them in their respective collections
    aPiece = new Queen(true);
    aSquare = Board::getBoard()->squareAt(3, 0);
    aSquare->setOccupier(aPiece);
    aPiece->setLocation(aSquare);
    whitePieces.insert(aPiece);
    aPiece = new Queen(false);
    aSquare = Board::getBoard()->squareAt(3, 7);
    aSquare->setOccupier(aPiece);
    aPiece->setLocation(aSquare);
    blackPieces.insert(aPiece);

    aPiece = new Bishop(true);
    aSquare = Board::getBoard()->squareAt(2, 0);
    aSquare->setOccupier(aPiece);
    aPiece->setLocation(aSquare);
    whitePieces.insert(aPiece);
    aPiece = new Bishop(false);
    aSquare = Board::getBoard()->squareAt(2, 7);
    aSquare->setOccupier(aPiece);
    aPiece->setLocation(aSquare);
    blackPieces.insert(aPiece);
    
}