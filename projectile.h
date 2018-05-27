#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Projectile: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Projectile(QGraphicsItem *parent = 0);
public slots:
    void shot();
};

#endif // PROJECTILE_H
