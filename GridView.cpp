#include <QTimer>
#include <QGraphicsLineItem>
#include "Grid.h"

Grid::Grid()
    : QGraphicsView()
    , _font("Courier",12)
    , _fontMetrics(_font)
{
    for(size_t x = 0; x < columnCount() + 1; x++) {
      int line_x = x * columnWidth();
      _scene.addLine(line_x, 0, line_x, rowCount() * rowHeight())->setPen(QPen(Qt::gray));
    }

    for(size_t y = 0; y < rowCount() + 1; y++) {
      int line_y = y * rowHeight();
      _scene.addLine(0, line_y, columnCount() * columnWidth(), line_y)->setPen(QPen(Qt::gray));
    }

    for(size_t y = 0; y < rowCount(); y++)
        _rows.emplace(y, *this);

    QGraphicsView::setScene(&_scene);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, QOverload<>::of(&GridView::updateMe));
    _timer->start(1000);
}

void Grid::updateMe()
{
    for (auto cell : _cells)
        cell.changeValue();

    invalidateScene();
}
