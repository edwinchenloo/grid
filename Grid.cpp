#include <QTimer>
#include <QGraphicsLineItem>
#include "Grid.h"

Grid::Grid()
    : QGraphicsView()
    , _font("Courier",12)
    , _fontMetrics(_font)
{
    QPen pen(Qt::gray);

    // Draw column vertical lines
    for(size_t x = columnCount() * columnWidth(); x > 0; x -= columnWidth())
      _scene.addLine(x, 0, x, rowCount() * rowHeight())->setPen(pen);

    // Draw row horizontal lines
    for(size_t y = rowCount() * rowHeight(); y > 0; y -= rowHeight())
      _scene.addLine(0, y, columnCount() * columnWidth(), y)->setPen(pen);

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
