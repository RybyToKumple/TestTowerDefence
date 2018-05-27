#include "game.h"
#include "tower.h"
#include "enemy.h"
#include "projectile.h"
#include "buildmode.h"
#include <QString>
#include <QGraphicsPixmapItem>


Game::Game()
{
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//cursor
    cursor = nullptr;
    letsBuildMode = nullptr;
    setMouseTracking(true);


//scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

//tower
    Tower *tower1 = new Tower();
    tower1->setPos(250,250);

//tower + scene
    scene->addItem(tower1);

//enemy
    Enemy * enemy1 = new Enemy();
    scene->addItem(enemy1);

    BuildMode * towerIcon = new BuildMode();
    scene->addItem(towerIcon);

    //setCursor(":/Towers/tower1.png");
}

void Game::mousePressEvent(QMouseEvent *mousePress)
{
//    Projectile * projectile = new Projectile();
//    projectile->setPos(mousePress->pos()); //position where we clicked
//    projectile->setRotation(40);
//    scene->addItem(projectile);
    if(letsBuildMode){
        scene->addItem(letsBuildMode);
        letsBuildMode->setPos(mousePress->pos());
        cursor = nullptr;  //change to normal cursor
        letsBuildMode = nullptr;

    }else{
        QGraphicsView::mousePressEvent(mousePress); //if we are not in build mode just do normal stuff
    }

}

void Game::mouseMoveEvent(QMouseEvent *mouseMove)
{
    if(cursor){
        cursor->setPos(mouseMove->pos());
    }
}

void Game::setCursor(QString filename)
{
        if (cursor){
              scene->removeItem(cursor);
              delete cursor;
          }

          cursor = new QGraphicsPixmapItem();
          cursor->setPixmap(QPixmap(filename));
          scene->addItem(cursor);
}
