#pragma once

class QGraphicsSimpleTextItem;

class Cell
{
public:
    Cell(QGraphicsSimpleTextItem* item, qreal x, qreal y);

    void changeValue();

protected:
    QGraphicsSimpleTextItem* _item;
};

