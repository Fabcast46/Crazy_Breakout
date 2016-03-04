#include "menuwindow.h"
#include "game.h"
#include "Server.h"
#include <QApplication>

Game * game;

int score = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menuWindow w;
    w.show();

    Server server;
    server.startServer();

    return a.exec();
}
