#ifndef QUEEN_H
#define QUEEN_H

#include "main.h"
#include "piece.h"

class Queen:public Piece{
public:
    Queen(int row, int column, Color color);

    void setMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;
};

#endif