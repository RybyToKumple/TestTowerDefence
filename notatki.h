#ifndef NOTATKI_H
#define NOTATKI_H
/*
game class inherits from QGraphicsView which is a widget, which is by default hidden, thats why we use show()

#2

    towerRange = new QGraphicsPolygonItem(polygon); items have to be added to the scene,
                                                if we get this item a parent it will be automatically
                                                added to the scene, thats why we add "this"
    towerRange = new QGraphicsPolygonItem(polygon,this);

#3

    we are making the bullet the parent of QTimer, so when bullet die, the timer also die

#4

    connect(shotTimer, SIGNAL(timeout()), this, SLOT(shot()));
                            =
    connect(shotTimer, SIGNAL(timeout()), bullet, SLOT(shot()))
#5

   - we need to check if the current item is an enemy
   - to do this we can use dynamic_cast
   - dynamic_cast will attempt to convert one pointer type into another pointer type
     if it's possible
   - so we want to convert general QGraphicsItem pointer(collidingItems() returns that pointer)
     into enemy pointer
   - if the cast is successful we are going to get pointer to the object
*/
#endif // NOTATKI_H

