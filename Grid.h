#pragma once
#include "GridPch.h"
#include "Row.h"

class Grid
    : public QGraphicsView
{
    Q_OBJECT

public:
    Grid();

    size_t columnCount() const { return 150; }
    size_t rowCount() const { return 600; }
    size_t columnWidth() const { return _columnWidth; }
    size_t rowHeight() const { return _rowHeight; }
    QGraphicsScene& scene() { return _scene; }
    const QFontMetrics& fontMetrics() const { return _fontMetrics; }

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
    size_t         _rowHeight{}, _columnWidth{};
};
