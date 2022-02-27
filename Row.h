#pragma once
#include "Cell.h"

class Grid;

class Row
{
public:
    using Cells = std::vector<Cell>;

    Row(Grid& grid, size_t index);

    void changeValue(size_t start, size_t end);
    const QRectF& rect() const { return _rect; }
    size_t index() const { return _index; }
    const Cells& cells() const { return _cells; }
    Grid& grid() { return _grid; }
    const Grid& grid() const { return _grid; }

protected:
    Grid& _grid;
    const size_t _index;
    Cells _cells;
    QRectF _rect;
};
