#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>

#include "paddle.h"
#include "ball.h"
#include "block.h"
#include "score.h"
#include "health.h"

class Game: public QGraphicsView{
public:

    Game(QWidget* parent=NULL);

    void start();
    void createBlockCol(double x);
    void creatBlockGrid();
    void setScore(int);

    QGraphicsScene* scene;

    Score * score;
    Health * health;

};

#endif // GAME_H
