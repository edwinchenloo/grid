#include <QGraphicsSimpleTextItem>
#include "Row.h"
#include "Grid.h"

Row::Row(size_t index, Grid& grid)
    : _index(index)
{
    for (size_t column = 0; column < grid.columnCount(); ++column)
    {
        QGraphicsSimpleTextItem* item = grid.scene().addSimpleText(" ", grid.font());
        _cells.emplace_back(item, column * grid.columnWidth() + grid.padding(), index * grid.rowHeight() + grid.padding());
    }
}

void Row::changeValue()
{
    for (Cell& cell : _cells)
        cell.changeValue();
}
