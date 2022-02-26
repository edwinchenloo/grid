#include <QFont>
#include <QFontMetrics>
#include <QTimer>
#include "GridView.h"

GridView::GridView()
    : QGraphicsView()
{
    QFont font("Courier",12);
    QFontMetrics font_metrics(font);
    int padding = 2;
    int column_width = font_metrics.horizontalAdvance("X") + padding * 2;
    int row_height = font_metrics.height() + padding * 2;
    int rows = 200, columns = 100;

    for(int x = 0; x < columns + 1; x++) {
      int line_x = x * column_width;
      _scene.addLine(line_x, 0, line_x, rows * row_height)->setPen(QPen(Qt::gray));
    }

    for(int y = 0; y < rows + 1; y++) {
      int line_y = y * row_height;
      _scene.addLine(0, line_y, columns * column_width, line_y)->setPen(QPen(Qt::gray));
    }

    for(int x = 0; x < columns; x++) {
      for(int y = 0; y < rows; y++) {
            QGraphicsSimpleTextItem* item = _scene.addSimpleText(QString().setNum(rand() % 10), font);
            _items.emplace_back(item);
            item->setPos(x * column_width + padding, y * row_height + padding);
      }
    }
    setScene(&_scene);

    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, QOverload<>::of(&GridView::updateMe));
    _timer->start(1000);
}

GridView::~GridView()
{
    for (auto item : _items)
        delete item;
}

void GridView::updateMe()
{
    for (auto item : _items)
        item->setText(QString().setNum(rand() % 10));

    invalidateScene();
}
