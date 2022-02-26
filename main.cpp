#include <QApplication>
#include "GridView.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GridView view;
    view.resize(700, 700);
    view.show();

    return app.exec();
}
