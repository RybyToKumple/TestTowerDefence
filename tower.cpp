#include "tower.h"
#include "game.h"
#include "enemy.h"
#include "projectile.h"
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>
#include <QList>
#include <QtMath>
#include <qmath.h>
#include <QLineF>
#include <QGraphicsRectItem>
#include <QPainter>
extern Game * game;
Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
//set the graphics
    setPixmap(QPixmap(":/Towers/tower1.png"));

    QPointF towerCenter(x() + this->pixmap().width()/2, y() + this->pixmap().height()/2);

//polygon
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2)
           << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    float SCALE_FACTOR = 80;
    for(size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    QPolygonF polygon(points);

    towerRange = new QGraphicsPolygonItem(polygon,this); //#2
   //scene()->addItem(towerRange);

//moving polygon center to tower center
    QPointF polyCenter(1.5,1.5);
    polyCenter *= SCALE_FACTOR;
    polyCenter = mapToScene(polyCenter);

//QPointF towerCenter(x() + this->pixmap().width()/2, y() + this->pixmap().height()/2);

    QLineF ln(polyCenter,towerCenter);
    towerRange->setPos(x()+ln.dx(),y()+ln.dy());

//connecting timer to towetAttackDestination
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(aquireEnemy()));
    timer->start(1000);


}

double Tower::distanceToItem(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::attackEnemy()
{
    QPointF towerCenter(x() + this->pixmap().width()/2, y() + this->pixmap().height()/2);


    Projectile * projectile = new Projectile();  //we create projectile
    projectile->setPos(towerCenter);             //set projectile in the tower center

    QLineF ln(towerCenter,towerAttackDestination); //make a line from tower center to tower attack destination
    //int angle = -1 * ln.angle(); //to make it clockwise

    float xDiff = towerAttackDestination.x() - towerCenter.x();
    float yDiff = towerAttackDestination.y() - towerCenter.y();
          //  return Math.Atan2(yDiff, xDiff) * (180 / Math.PI)
    double k = qAtan2(xDiff,yDiff);
    double l = k * 57.32;
    projectile->setRotation(l);
    game->scene->addItem(projectile);
}

void Tower::aquireEnemy()
{
    QList<QGraphicsItem *> collidingItemsList = towerRange->collidingItems(); //towerRange is a polygon

    if(collidingItemsList.size() == 1){
        enemyInRange = false;
        return;
    }

    double closestDistanceToEnemy = 300;
    QPointF closestPoint = QPointF(0,0);

    for(size_t i = 0, n = collidingItemsList.size(); i < n; i++){
        Enemy * enemy = dynamic_cast<Enemy *>(collidingItemsList[i]); //#4 if the item is an enemy
        if(enemy){
            double distanceToEnemy = distanceToItem(enemy);
            if(distanceToEnemy < closestDistanceToEnemy){
                closestDistanceToEnemy = distanceToEnemy;
                closestPoint = collidingItemsList[i]->pos();
                enemyInRange = true;
            }
        }

    }

    towerAttackDestination = closestPoint;
    attackEnemy();
}
