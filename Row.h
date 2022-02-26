#pragma once
#include <vector>
#include "Cell.h"

class Grid;

class Row
{
public:
    Row(size_t index, Grid& grid);

    void changeValue();

protected:
    using Cells = std::vector<Cell>;

    size_t _index;
    Cells _cells;
};
