#ifndef HEALTH_H
#define HEALTH_H

#include <QFont>
#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    int decrease1();
    int decrease2();
    int decrease3();
    int getHealth();
private:
    int health;
};


#endif // HEALTH_H
