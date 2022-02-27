#pragma once

class Grid;
class QGraphicsSimpleTextItem;
class Row;

class Cell
{
public:
    Cell(Row& row, std::size_t column);

    void changeValue();
    const QRect& rect() const { return _rect; }
    size_t index() const { return _index; }
    Row& row() { return _row; }
    const Row& row() const { return _row; }
    void setColor(const QColor& color);
    void setAlignment(Qt::AlignmentFlag alignment) { _alignment = alignment; }
    void setValue(const QString& value);

protected:
    QString _value;
    QGraphicsSimpleTextItem* _item;
    QRect _rect;
    Row& _row;
    const size_t _index;
    size_t _ypadding{};
    Qt::AlignmentFlag _alignment { Qt::AlignHCenter };
};

