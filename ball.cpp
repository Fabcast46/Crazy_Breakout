#include "ball.h"

Health* health;

Ball::Ball(QGraphicsItem *parent): QGraphicsRectItem(parent), QObject(){
    setRect(0,0,10,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    xVelocity = 0;
    yVelocity = -5;
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
    health = new Health();
}

double Ball::getCenterX(){
    return x() + rect().width()/2;
}

void Ball::move(){    
    boundsCollision();
    paddleCollision();
    blockCollision();
    moveBy(xVelocity,yVelocity);
}

void Ball::boundsCollision(){
    double screenW = 624;
    double screenH = 500;
    int hp = health->getHealth();
    // left
    if (mapToScene(rect().topLeft()).x() <= 0){
        xVelocity = -1 * xVelocity;
    }
    // right
    if (mapToScene(rect().topRight()).x() >= screenW){
        xVelocity = -1 * xVelocity;
    }
    // top
    if (mapToScene(rect().topLeft()).y() <= 0){
        yVelocity = -1 * yVelocity;
    }
    // bottom
    if (mapToScene(rect().topRight()).y() >= screenH){
        yVelocity = -1 * yVelocity;
        if(hp == 3){
            health->decrease1();
        }
        else if(hp == 2){
            health->decrease2();
        }
        else if(hp == 1){
            health->decrease3();
        }
        else{
            qDebug() << "Game Over " << "\n";
            delete this;
        }
    }
}

void Ball::paddleCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            yVelocity = -1 * yVelocity;
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();
            double dvx = ballX - paddleX;
            xVelocity = (xVelocity + dvx)/15;
        }
    }
}

void Ball::blockCollision(){
    Score* score = new Score();
    scor = score->getScore();
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        // collides with block
        if (block){
            double yPad = 5;
            double xPad = 5;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();
            // collides from bottom
            if (bally > blocky + yPad && yVelocity < 0){
                yVelocity = -1 * yVelocity;
                //score->increase();
            }
            // collides from top
            if (blocky > bally + yPad && yVelocity > 0 ){
                yVelocity = -1 * yVelocity;
                //score->increase();
            }
            // collides from right
            if (ballx > blockx + xPad && xVelocity < 0){
                xVelocity = -1 * xVelocity;
                //score->increase();
            }
            // collides from left
            if (blockx > ballx + xPad && xVelocity > 0){
                xVelocity = -1 * xVelocity;
            }
            delete block;
            scor++;
        }
    }
}
