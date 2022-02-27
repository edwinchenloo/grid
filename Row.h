#pragma once
#include "Cell.h"

class Grid;

class Row
{
public:
    Row(size_t index, Grid& grid);

    void changeValue(const QRect& area);
    const QRect& rect() const { return _rect; }

protected:
    using Cells = std::vector<Cell>;

    size_t _index;
    Cells _cells;
    QRect _rect;
};
