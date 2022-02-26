#include <QTimer>
#include <QGraphicsLineItem>
#include "Grid.h"

Grid::Grid()
    : QGraphicsView()
    , _font("Courier",12)
    , _fontMetrics(_font)
{
    for(size_t x = 0; x < columnCount() + 1; x++) {
      size_t line_x = x * columnWidth();
      _scene.addLine(line_x, 0, line_x, rowCount() * rowHeight())->setPen(QPen(Qt::gray));
    }

    for(size_t y = 0; y < rowCount() + 1; y++) {
      size_t line_y = y * rowHeight();
      _scene.addLine(0, line_y, columnCount() * columnWidth(), line_y)->setPen(QPen(Qt::gray));
    }

    _rows.reserve(rowCount());
    for(size_t y = 0; y < rowCount(); y++)
        _rows.emplace_back(y, *this);

    QGraphicsView::setScene(&_scene);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, QOverload<>::of(&Grid::updateMe));
    _timer->start(1000);
}

void Grid::updateMe()
{
    for (auto row : _rows)
        row.changeValue();

    invalidateScene();
}
