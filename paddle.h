#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QBrush>
#include <QDebug>

class Paddle: public QGraphicsRectItem{
public:
    Paddle();


    double getCenterX();

    void keyPressEvent(QKeyEvent *event);


};

#endif // PADDLE_H
