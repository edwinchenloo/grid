#include "GridPch.h"
#include "Row.h"
#include "Grid.h"

Row::Row(Grid& grid, size_t index)
    : _grid(grid)
    , _index(index)
{
    for (size_t column = 0; column < grid.columnCount(); ++column)
        _cells.emplace_back(*this, column);

    if (!_cells.empty())
    {
        _rect = (*_cells.begin()).rect();
        _rect.setWidth((int)(_cells.size() * grid.columnWidth()));
        //qDebug("Row %zu (%d,%d) (%d,%d)", index, _rect.left(), _rect.top(), _rect.right(), _rect.bottom());
    }
}

void Row::changeValue(size_t start, size_t end)
{
    for(; start < end; ++start)
       _cells[start].changeValue();
}
