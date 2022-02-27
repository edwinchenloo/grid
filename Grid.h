#pragma once
#include "GridPch.h"
#include "Row.h"

class Grid
    : public QGraphicsView
{
    Q_OBJECT

public:
    Grid();

    size_t padding() const { return 0; }
    size_t columnCount() const { return 100; }
    size_t rowCount() const { return 200; }
    size_t columnWidth() const { return _fontMetrics.horizontalAdvance("X"); };
    size_t rowHeight() const { return _fontMetrics.height(); }
    QGraphicsScene& scene() { return _scene; }

public slots:
    void onTimer();
    void onHorizontalScroll(int h);
    void onVerticalScroll(int v);

protected:
    void resizeEvent(QResizeEvent* event) override;

    QGraphicsScene _scene;
    QTimer*        _timer{};
    std::vector<Row> _rows;
    QFont           _font;
    QFontMetrics    _fontMetrics;
    QRect           _area;
};