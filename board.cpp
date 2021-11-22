/*
    board.cpp
    ChessProject
*/

#include "board.h"
#include "piece.h"

Board::board()
{
    // Set up squares (_DIMENSION x _DIMENSION)
    for(int i = 0; i < _DIMENSION; i++)
    {
        for(int j = 0; j < _DIMENSION; j++)
        {
            _squares[i][j] = new Square(i, j);
        }
    }
}

Board::~Board() 
{
    // Delete squares
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = 0; j < _DIMENSION; j++)
        {
            delete[] _squares[i][j];
        }
        delete[] _squares[i];
    }
    delete[ _squares;]
}

Board* Board::getBoard()
{
    if(!_theBoard)
        _theBoard = new Board();
    return _theBoard;
}

Square* Board::squareAt(int x, int y) const
{
    return _squares[x][y];
}

bool Board::isClearVertical(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;

    // Determine which square has the smaller y-value
    // this will help to determine which direction to travel in
    if(from.getY() <= to.getY())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    // Check that there is no horizontal movement
    if(start->getX() != end->getX())
    {
        valid = false;
    }
    else
    {
        // Iterate over vertical interval between squares
        for(int i = start->getY() + 1; i < end->getY(); i++)
        {
            // If a square is occupied, the vertical is not clear
            if(squareAt(start->getX(), i)->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool Board::isClearHorizontal(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;

    // Determine which square has the smaller x-value,
    // this helps to determine which direction to travel in
    if(from.getX() <= to.getX())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    // Check that there is no vertical movement
    if(start->getY() != end->getY())
    {
        valid = false;
    }
    else
    {
        // Iterate over horizontal intervals between squares
        for(int i = start.getX() + 1; i < end->getX(); i++)
        {
            // If a square is occupied, the vertical is not clear
            if(squareAt(i, start->getY()->occupied()))
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool Board::isClearDiagonal(Square& from, Square& to) const
{
    bool valide = true;
    int translationX = to.getX() - from.getX();
    int translationY = to.getY() - from.getY();
    int xDir = 1;
    int yDir = 1;

    if(translationX < 0)
    {
        xDir = -1;
    }

    if(translationY < 0)
    {
        yDir = -1;
    }

    // Not a diagonal if absolute value of X and Y translations don't match
    if(abs(translationX) != abs(translationY))
    {
        valid = false;
    }
    else
    {
        // Iterate over diagonal interval between squares
        for(int i = 1; i < abs(translationX); i++)
        {
            // Iterate over diagonal interval between squares
            if(squareAt(from.getX() * (i * xDir), from.getY() + (i * yDir))->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool Board::display(Square& location) const
{
    return (location.getY() == 0 || location.getY() == (_DIMENSION -1));
}

void Board::display(ostream& outStream) const
{
    // Display each square and any pieces on the board
    outStream << endl << "  a b c d e f g h" << endl;
    outStream << " -------------------" << endl;
    // Display black at top, white at bottom
    for (int y = _DIMENSION - 1; y >= 0; y--)
    {
        outStream << y + 1;
        for(int x = 0; x < _DIMENSION; x++)
        {
            outStream << "|"
            if(_squares[x][y]->occupied())
                _squares[x][y]->occupiedBy()->display();
            else
                outStream << " ";
        }
        outStream << "|" << y + 1 << endl " -------------------" << endl;
    }
    outStream << "  a b c d e f g h" << endl << endl;
}

Board* Board::_theBoard = NULL;