#include "GridPch.h"
#include "Grid.h"

size_t gMaxX = 0;
size_t gMaxY = 0;

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

    connect(verticalScrollBar(), &QScrollBar::valueChanged, this, &Grid::onVerticalScroll);
    connect(horizontalScrollBar(), &QScrollBar::valueChanged, this, &Grid::onHorizontalScroll);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, QOverload<>::of(&Grid::onTimer));
    _timer->start(1000);

    qDebug("max x:%zu y:%zu", gMaxX, gMaxY);
}

void Grid::onTimer()
{
    //qDebug("refreshing (%d,%d) (%d,%d)", _area.left(), _area.top(), _area.right(), _area.bottom());

    for (Row& row : _rows)
        row.changeValue(_area);

    invalidateScene();
}

void Grid::onHorizontalScroll(int h)
{
    _area.moveLeft(h);
    qDebug("h:%d %d", _area.left(), _area.right());
}

void Grid::onVerticalScroll(int v)
{
    _area.moveTop(v);
    qDebug("v:%d %d", _area.top(), _area.bottom());
}

void Grid::resizeEvent(QResizeEvent* event)
{
    _area.setSize(event->size());
    qDebug("size %d x %d", _area.width(), _area.height());
    QGraphicsView::resizeEvent(event);
}
