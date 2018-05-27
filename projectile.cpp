#include "projectile.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Projectile::Projectile(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Projectiles/bullet1"));

    QTimer *shotTimer = new QTimer(this); //#3
    connect(shotTimer, SIGNAL(timeout()), this, SLOT(shot())); //#4
    shotTimer->start(50);
}

void Projectile::shot()
{
    int shotRange = 30;
    double theta = rotation(); //returns degrees

    double dx = shotRange * qSin(qDegreesToRadians(theta));
    double dy = shotRange * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


}
