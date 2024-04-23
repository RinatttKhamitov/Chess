#include "pawn.h"
#include "board.h"

extern Board* board;

Pawn::Pawn(int row, int column, Color color) : Piece(row, column, color){
    firstMove = true;
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Pawn.png");
    else 
        image = QPixmap(":/Chess/images/Black_Pawn.png");
}   

bool Pawn::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Pawn::set_BottomPlayerMoves(){
    Color enemyColor = (board->currentMoveColor == Color::white)? Color::black : Color::white;
    if(row-1 < 0) return;

    if(isValidMove(row-1, column+1)){
        if(board->squares[row-1][column+1]->piece->color == enemyColor){
            board->squares[row-1][column+1]->piece->isTarget = true;
            board->squares[row-1][column+1]->update();
        }
    }
    if(isValidMove(row-1, column-1)){
        if(board->squares[row-1][column-1]->piece->color == enemyColor){
            board->squares[row-1][column-1]->piece->isTarget = true;
            board->squares[row-1][column-1]->update();
        }
    }

    int moves = firstMove? 2: 1;
    for(int i = 1; i <= moves; i++){
        if(board->squares[row-i][column]->piece->color != Color::nonExistent)
            break;
        
        possibleMovesCoords.push_back({row-i, column});
    }
}

void Pawn::set_TopPlayerMoves(){
    Color enemyColor = (board->currentMoveColor == Color::white)? Color::black : Color::white;
    if(row+1 > 7) return;

    if(isValidMove(row, column+1)){
        if(board->squares[row+1][column+1]->piece->color == enemyColor){
            board->squares[row+1][column+1]->piece->isTarget = true;
            board->squares[row+1][column+1]->update();
        }
    }
    if(isValidMove(row, column-1)){
        if(board->squares[row+1][column-1]->piece->color == enemyColor){
            board->squares[row+1][column-1]->piece->isTarget = true;
            board->squares[row+1][column-1]->update();
        }
    }
    int moves = firstMove? 2: 1;
    for(int i = 1; i <= moves; i++){
        if(board->squares[row+i][column]->piece->color != Color::nonExistent)
            break;
        possibleMovesCoords.push_back({row+i, column});
    }
}

void Pawn::setMoves(){
    if(board->currentMoveColor == board->firstTurnColor){
        set_BottomPlayerMoves();
    }
    else{
        set_TopPlayerMoves();
    }
}

void Pawn::showMoves(QGraphicsScene* scene){
    for(Coordinates move : possibleMovesCoords){
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
            88+move.column*100, 88+move.row*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[move.row][move.column]->turnMarker = turn;
        turns.append(turn);
        scene->addItem(turn);
    }
}

void Pawn::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
    }
    possibleMovesCoords.clear();
}