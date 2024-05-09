#include "main.h"
#include "board.h"

#include "formMainMenu.h"
#include "formMenuChooseColor.h"
#include "formEndGame.h"
#include "menuController.h"

#include <QProcess>
#include <QDebug>


// TODO: использовать только нужные библиотеки и хедеры в каждом файле
// Узнать начсет структуры и как сделать адекватно взятие на проходе

Board* board;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    MenuController menuController;
    return app.exec();
    
}
