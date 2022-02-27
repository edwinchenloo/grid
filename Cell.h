#pragma once

class Grid;
class QGraphicsSimpleTextItem;

class Cell
{
public:
    Cell(Grid& grid, std::size_t row, std::size_t column);

    void changeValue(const QRect& area);
    const QRect& rect() const { return _rect; }

protected:
    QGraphicsSimpleTextItem* _item;
    QRect _rect;
};

