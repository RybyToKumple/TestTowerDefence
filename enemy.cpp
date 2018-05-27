#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Enemy::Enemy(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Enemies/enemy1"));

//setting the path
    points << QPointF(200,200) << QPointF(200,400);
    pointIndex = 0;
    destination = points[0];
//setting direction
    rotateEnemyToPoint(destination);


//moving enemies
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer->start(100);
}

void Enemy::rotateEnemyToPoint(QPointF p)
{
    QLineF ln(pos(),p);  //from our position to place we need to face
    setRotation(-1 * ln.angle());
}

void Enemy::moveEnemy()
{
//    int i = 0;
//    if(pos() == points[i]){
//        destination = points[i+1];
//        rotateEnemyToPoint(destination);
//        i++;
//    }

    QLineF ln(pos(), destination);
    if(ln.length() < 5){
        pointIndex++;
        if(pointIndex >= points.size())
            return;
        destination = points[pointIndex];
        rotateEnemyToPoint(destination);
    }

    int shotRange = 5;
    double theta = rotation(); //returns degrees

    double dx = shotRange * qSin(qDegreesToRadians(theta));
    double dy = shotRange * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
