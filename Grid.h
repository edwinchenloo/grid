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
    size_t columnCount() const { return 150; }
    size_t rowCount() const { return 600; }
    size_t columnWidth() const { return _fontMetrics.horizontalAdvance("000,000"); };
    size_t rowHeight() const { return _fontMetrics.height(); }
    QGraphicsScene& scene() { return _scene; }

public slots:
    void onTimer();
    void onHorizontalScroll(int h);
    void onVerticalScroll(int v);

protected:
    using Rows = std::vector<Row>;

    void resizeEvent(QResizeEvent* event) override;
    void calcRows();
    void calcColumns();

    QGraphicsScene _scene;
    QTimer*        _timer{};
    Rows           _rows;
    QFont          _font;
    QFontMetrics   _fontMetrics;
    QRect          _area;
    Rows::iterator _itRowStart, _itRowEnd;
    size_t         _columnStart{}, _columnEnd{1};
};
