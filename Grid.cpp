#include "GridPch.h"
#include "Grid.h"

//size_t gMaxX = 0;
//size_t gMaxY = 0;

Grid::Grid()
    : QGraphicsView()
    , _font("Courier New",12)
    , _fontMetrics(_font)
{
    QPen pen(Qt::lightGray);
    _font.setStyleHint(QFont::Monospace);
    _font.setStyleStrategy(QFont::PreferAntialias);

    QFontMetrics fontMetrics(_font);
    _fontMetrics.swap(fontMetrics);

    _columnWidth = _fontMetrics.horizontalAdvance("000,000");
    _rowHeight = _fontMetrics.height();

    _scene = new QGraphicsScene;

    // Draw column vertical lines
    for(size_t x = columnCount() * columnWidth(); x > 0; x -= columnWidth())
      _scene->addLine(x, 0, x, rowCount() * rowHeight())->setPen(pen);

    // Draw row horizontal lines
    for(size_t y = rowCount() * rowHeight(); y > 0; y -= rowHeight())
      _scene->addLine(0, y, columnCount() * columnWidth(), y)->setPen(pen);

    _rows.reserve(rowCount());
    for(size_t y = 0; y < rowCount(); y++)
        _rows.emplace_back(*this, y);

    QGraphicsView::setScene(_scene);

    connect(verticalScrollBar(), &QScrollBar::valueChanged, this, &Grid::onVerticalScroll);
    connect(horizontalScrollBar(), &QScrollBar::valueChanged, this, &Grid::onHorizontalScroll);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, QOverload<>::of(&Grid::onTimer));
    _timer->start(1000);

    //qDebug("max x:%zu y:%zu", gMaxX, gMaxY);
}

void Grid::onTimer()
{
    //qDebug("refreshing (%d,%d) (%d,%d)", _area.left(), _area.top(), _area.right(), _area.bottom());

    if (_rows.empty())
        return;

    //qDebug("refresh col %zu to %zu", columnStart, columnEnd);

    for (Rows::iterator itRow = _itRowStart; itRow != _itRowEnd; ++itRow)
        (*itRow).changeValue(_columnStart, _columnEnd);

    invalidateScene();
}

void Grid::onHorizontalScroll(int h)
{
    _area.moveLeft(h);
    qDebug("h:%d %d", _area.left(), _area.right());

    calcColumns();
}

void Grid::onVerticalScroll(int v)
{
    _area.moveTop(v);
    qDebug("v:%d %d", _area.top(), _area.bottom());

    calcRows();
}

void Grid::resizeEvent(QResizeEvent* event)
{
    _area.setSize(event->size());
    qDebug("size %d x %d", _area.width(), _area.height());
    QGraphicsView::resizeEvent(event);

    calcRows();
    calcColumns();
}

void Grid::calcRows()
{
    _itRowEnd = std::upper_bound(_rows.begin(), _rows.end(), _area.bottom(),
                                            [](int bottom, const Row& row) -> bool
                                            {
                                               return (row.rect().top() > bottom);
                                            });
    _itRowStart = std::lower_bound(_rows.begin(), _rows.end(), _area.top(),
                                             [](const Row& row, int top) -> bool
                                             {
                                                return (row.rect().bottom() < top);
                                             });
}

void Grid::calcColumns()
{
    const Row& row = *_rows.begin();
    auto itColumnEnd = std::upper_bound(row.cells().begin(), row.cells().end(), _area.right(),
                                        [](int right, const Cell& cell) -> bool
                                        {
                                            return (cell.rect().left() >= right);
                                        });
    auto itColumn = std::lower_bound(row.cells().begin(), row.cells().end(), _area.left(),
                                     [](const Cell& cell, int left) -> bool
                                     {
                                         return (cell.rect().right() < left);
                                     });
    _columnStart = (*itColumn).index();
    _columnEnd = (itColumnEnd == row.cells().end() ? columnCount() : (*itColumnEnd).index());
}

