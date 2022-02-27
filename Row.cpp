#include "GridPch.h"
#include "Row.h"
#include "Grid.h"

Row::Row(size_t index, Grid& grid)
    : _index(index)
{
    for (size_t column = 0; column < grid.columnCount(); ++column)
        _cells.emplace_back(grid, index, column);

    if (!_cells.empty())
    {
        _rect = (*_cells.begin()).rect();
        _rect.setWidth(_cells.size() * grid.columnWidth());
        //qDebug("Row %zu (%d,%d) (%d,%d)", index, _rect.left(), _rect.top(), _rect.right(), _rect.bottom());
    }
}

void Row::changeValue(const QRect& area)
{
    if (rect().top() >= area.bottom())
        return;

    if (rect().bottom() <= area.top())
        return;

    //qDebug("row %zu refresh (%d,%d) (%d,%d)", _index, rect().left(), rect().top(), rect().right(), rect().bottom());

    for (Cell& cell : _cells)
        cell.changeValue(area);
}
