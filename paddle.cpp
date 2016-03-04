#include "paddle.h"


Paddle::Paddle(){
    setRect(0,0,100,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}

double Paddle::getCenterX(){
    return x()+rect().width()/2;
}



void Paddle::keyPressEvent(QKeyEvent *event){    
    if(event->key() == Qt::Key_Left){
        if(x()>5)
            setPos(x()-20,y());
        else
            setPos(x(),y());
        //qDebug() << "Izquierda";
    }
    else if(event->key() == Qt::Key_Right){
        if(x()<530)
            setPos(x()+20,y());
        else
            setPos(x(),y());
        //qDebug() << "Derecha";
    }

}
