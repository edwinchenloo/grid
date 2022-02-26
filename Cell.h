#pragma once

class Grid;
class QGraphicsSimpleTextItem;

class Cell
{
public:
    Cell(Grid& grid, size_t row, size_t column);

    void changeValue();

protected:
    QGraphicsSimpleTextItem* _item;
};

