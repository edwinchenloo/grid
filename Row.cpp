#include <QGraphicsSimpleTextItem>
#include "Row.h"
#include "Grid.h"

Row::Row(size_t index, Grid& grid)
    : _index(index)
{
    for (size_t column = 0; column < grid.columnCount(); ++column)
    {
        _cells.emplace_back(grid, index, column);
    }
}

void Row::changeValue()
{
    for (Cell& cell : _cells)
        cell.changeValue();
}
