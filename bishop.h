/*
    This class represents a chess bishop piece
*/

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
#include "square.h"

using namespace std;

class Bishop : public Piece
{
    public:

    /*
        Creates a bishop

        @param color the color of the piece
    */
   Bishop(bool isWhite);
}