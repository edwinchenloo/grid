#include "GridPch.h"
#include "Cell.h"
#include "Grid.h"

Cell::Cell(Row& row, size_t column)
    : _value("000x000")
    , _row(row)
    , _index(column)
{
    Grid& grid = row.grid();
    size_t x = column * grid.columnWidth();
    size_t y = row.index() * grid.rowHeight();

    QRectF rect((qreal)x, (qreal)y, (qreal)grid.columnWidth(), (qreal)grid.rowHeight());
    _rect = grid.scene().addRect(rect);
    _rect->setPen(Qt::NoPen);
    _rect->setOpacity(1.0);

    _text = grid.scene().addSimpleText(_value, grid.font());

    changeValue();
}

void Cell::changeValue()
{
    QString value(_value);
    value[3] = QChar('a' + (rand() % 26));
    setValue(value);

    setTextColor(rand() % 2 ? Qt::blue : Qt::red);
    setBackgroundColor(rand() % 2 ? QColor(244, 250, 202) : QColor(235, 230, 250));
}

void Cell::setValue(const QString& value)
{
    _value = value;
    _text->setText(_value);

    switch (_alignment)
    {
        case Qt::AlignmentFlag::AlignLeft:
            _text->setPos(rect().left(), rect().top() + _ypadding);
            break;
        case Qt::AlignmentFlag::AlignRight:
            {
            const QRectF bound = _text->boundingRect();
            _text->setPos(rect().right() - bound.width(), rect().top() + _ypadding);
            break;
            }
        case Qt::AlignmentFlag::AlignHCenter:
        default:
            {
            const QRectF bound = _text->boundingRect();
            _text->setPos(rect().left() + (rect().width() - bound.width())/2, rect().top() + _ypadding);
            break;
            }
    };
}

void Cell::setTextColor(const QColor& color)
{
    QBrush brush = _text->brush();
    brush.setColor(color);
    _text->setBrush(brush);
}

void Cell::setBackgroundColor(const QColor& color)
{
    _rect->setBrush(QBrush(color, Qt::SolidPattern));
}

