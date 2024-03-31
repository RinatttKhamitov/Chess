#ifndef KING_H
#define KING_H

#include "main.h"
#include "piece.h"

class King:public Piece{
public:
    King(int row, int column, Color color);

    void setMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;
};

#endif