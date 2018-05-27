#ifndef BUILDMODE_H
#define BUILDMODE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildMode : public QGraphicsPixmapItem
{
public:
    BuildMode(QGraphicsItem *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *mousePress);
};

#endif // BUILDMODE_H
