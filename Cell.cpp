#include <QGraphicsSimpleTextItem>
#include "Cell.h"

Cell::Cell(QGraphicsSimpleTextItem* item, qreal x, qreal y)
    : _item(item)
{
    _item->setPos(x, y);
}

void Cell::changeValue()
{
   _item->setText(QString().setNum(rand() % 10));
}
