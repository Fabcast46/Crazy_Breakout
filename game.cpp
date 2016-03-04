#include "game.h"

Game::Game(QWidget *parent): QGraphicsView(parent){
    scene = new QGraphicsScene(0,0,624,500);
    setScene(scene);    
}

void Game::start(){
    Paddle* paddle = new Paddle();
    paddle->setPos(150,460);
    scene->addItem(paddle);    
    paddle->grabKeyboard();
    Ball* ball = new Ball();
    ball->setPos(200,440);
    scene->addItem(ball);
    creatBlockGrid();


        // play background music
        //QMediaPlayer * music = new QMediaPlayer();
        //music->setMedia(QUrl("qrc:/sound/under.ogg"));
        //music->play();

    }

void Game::createBlockCol(double x){
    for (size_t i = 0, n = 5; i < n; ++i){
        Block* block = new Block();
        block->setPos(x,i*17);
        scene->addItem(block);
    }
}

void Game::creatBlockGrid(){
    for (size_t i = 0, n = 12; i < n; ++i){
        createBlockCol(i*52);
    }
}
