#include "score.h"


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){   
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int scor){
    //score++;
    setPlainText(QString("Score: ") + QString::number(scor));
    qDebug() << scor << "\n";
}

int Score::getScore(){
    return score;
}
