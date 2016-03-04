#include "health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int Health::decrease1(){
    health = 2;
    return health;
}

int Health::decrease2(){
    health = 1;
    return health;
}

int Health::decrease3(){
    health = 0;
    return health;
}

int Health::getHealth(){
    return health;
}
