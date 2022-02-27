#pragma once

class Grid;
class QGraphicsSimpleTextItem;
class Row;

class Cell
{
public:
    Cell(Grid& grid, const Row& row, std::size_t column);

    void changeValue();
    const QRect& rect() const { return _rect; }
    size_t index() const { return _index; }

protected:
    QString _value;
    QGraphicsSimpleTextItem* _item;
    QRect _rect;
    const Row& _row;
    const size_t _index;
};

