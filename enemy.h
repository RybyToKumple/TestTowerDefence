#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent = 0);
    void rotateEnemyToPoint(QPointF p);
public slots:
    void moveEnemy();
private:
    QList<QPointF> points;
    QPointF destination;
    int pointIndex;
};

#endif // ENEMY_H
