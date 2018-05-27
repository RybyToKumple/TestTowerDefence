#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "tower.h"

class Game : public QGraphicsView
{
public:
    Game();
    void mousePressEvent(QMouseEvent *mousePress);
    void mouseMoveEvent(QMouseEvent *mouseMove);
    void setCursor(QString filename);

    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower * letsBuildMode;
};

#endif // GAME_H
