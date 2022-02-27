#include "GridPch.h"
#include "Cell.h"
#include "Grid.h"

Cell::Cell(Row& row, size_t column)
    : _value("000x000")
    , _item(row.grid().scene().addSimpleText(_value, row.grid().font()))
    , _row(row)
    , _index(column)
{
    const Grid& grid = row.grid();
    size_t x = column * grid.columnWidth();
    size_t y = row.index() * grid.rowHeight();

    _rect.moveTo((int)x, (int)y);
    _rect.setWidth((int)grid.columnWidth());
    _rect.setHeight((int)grid.rowHeight());

    changeValue();
}

void Cell::changeValue()
{
    QString value(_value);
    value[3] = QChar('a' + (rand() % 26));
    setValue(value);

    setColor(rand() % 2 ? Qt::blue : Qt::red);
}

void Cell::setValue(const QString& value)
{
    _value = value;
    _item->setText(_value);

    switch (_alignment)
    {
        case Qt::AlignmentFlag::AlignLeft:
            _item->setPos(rect().left(), rect().top() + _ypadding);
            break;
        case Qt::AlignmentFlag::AlignRight:
            {
            const QRectF bound = _item->boundingRect();
            _item->setPos(rect().right() - bound.width(), rect().top() + _ypadding);
            break;
            }
        case Qt::AlignmentFlag::AlignHCenter:
        default:
            {
            const QRectF bound = _item->boundingRect();
            _item->setPos(rect().left() + (rect().width() - bound.width())/2, rect().top() + _ypadding);
            break;
            }
    };
}

void Cell::setColor(const QColor& color)
{
    QBrush brush = _item->brush();
    brush.setColor(color);
    _item->setBrush(brush);
}

