#include "GridPch.h"
#include "Cell.h"
#include "Grid.h"

Cell::Cell(Grid& grid, size_t row, size_t column)
    : _item(grid.scene().addSimpleText("0", grid.font()))
{
    size_t x = column * grid.columnWidth();
    size_t y = row * grid.rowHeight();
    _item->setPos(x + grid.padding() + 2, y + grid.padding());

    _rect.moveTo((int)x, (int)y);
    _rect.setWidth((int)grid.columnWidth());
    _rect.setHeight((int)grid.rowHeight());
}

void Cell::changeValue(const QRect& area)
{
    if (rect().left() >= area.right())
        return;

    if (rect().right() <= area.left())
        return;

   _item->setText(QString().setNum(rand() % 10));
}
