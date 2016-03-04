#include "block.h"

Block::Block(QGraphicsItem *parent): QGraphicsRectItem(parent){    
    setRect(0,0,50,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}
