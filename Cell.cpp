#include <QGraphicsSimpleTextItem>
#include "Cell.h"
#include "Grid.h"

Cell::Cell(Grid& grid, size_t row, size_t column)
    : _item(grid.scene().addSimpleText("0", grid.font()))
{
    qreal x = column * grid.columnWidth() + grid.padding() + 2;
    qreal y = row * grid.rowHeight() + grid.padding();
    _item->setPos(x, y);
}

void Cell::changeValue()
{
   _item->setText(QString().setNum(rand() % 10));
}
