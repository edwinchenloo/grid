#include "GridPch.h"
#include "Cell.h"
#include "Grid.h"

Cell::Cell(Grid& grid, const Row& row, size_t column)
    : _value("000,000")
    , _item(grid.scene().addSimpleText(_value, grid.font()))
    , _row(row)
    , _index(column)
{
    size_t x = column * grid.columnWidth();
    size_t y = row.index() * grid.rowHeight();
    _item->setPos(x + grid.padding() + 2, y + grid.padding());

    _rect.moveTo((int)x, (int)y);
    _rect.setWidth((int)grid.columnWidth());
    _rect.setHeight((int)grid.rowHeight());

    char sz[32];
    sprintf(sz, "%03zu,%03zu", row.index(), index());
    _value = sz;
}

void Cell::changeValue()//const QRect& area)
{
    //if (rect().left() >= area.right())
    //    return false;

    //if (rect().right() <= area.left())
    //    return false;

    _value[3] = QChar('a' + (rand() % 26));
   _item->setText(_value);
}
