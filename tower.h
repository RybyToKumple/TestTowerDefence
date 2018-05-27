#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>


class Tower : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent = 0);
    double distanceToItem(QGraphicsItem * item);
    void attackEnemy();
public slots:
    void aquireEnemy();

private:
    QGraphicsPolygonItem * towerRange;
    QPointF towerAttackDestination;
    bool enemyInRange;
};

#endif // TOWER_H
