#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <vector>

class GridView
    : public QGraphicsView
{
    Q_OBJECT

public:
    GridView();
    ~GridView();

public slots:
    void updateMe();

protected:
    QGraphicsScene _scene;
    QTimer*        _timer{};
    std::vector<QGraphicsSimpleTextItem*> _items;
};
