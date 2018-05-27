#include <QApplication>
#include <QDebug>
#include <game.h>

Game * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    qDebug() << "j";
    return a.exec();
}
