#include "buildmode.h"
#include "game.h"

extern Game * game;

BuildMode::BuildMode(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Towers/tower1"));
}

void BuildMode::mousePressEvent(QGraphicsSceneMouseEvent *mousePress)
{
    if(!game->letsBuildMode){
        game->letsBuildMode = new Tower();
        game->setCursor(QString(":/Towers/tower1.png"));
    }
}
