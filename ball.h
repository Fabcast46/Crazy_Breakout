#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
#include "game.h"
#include "paddle.h"
#include "block.h"
#include "score.h"
#include <QDebug>

class Ball: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Ball(QGraphicsItem* parent=NULL);

    double getCenterX();

    int i;
    int scor;

public slots:
    void move();

private:
    double xVelocity;
    double yVelocity;

    void boundsCollision();
    void paddleCollision();
    void blockCollision();

    int setScore(int);
};

#endif // BALL_H
