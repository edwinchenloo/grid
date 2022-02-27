#pragma once
#include "Cell.h"

class Grid;

class Row
{
public:
    using Cells = std::vector<Cell>;

    Row(size_t index, Grid& grid);

    void changeValue(size_t start, size_t end);
    const QRect& rect() const { return _rect; }
    size_t index() const { return _index; }
    const Cells& cells() const { return _cells; }

protected:
    size_t _index;
    Cells _cells;
    QRect _rect;
};
