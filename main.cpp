#include "GridPch.h"
#include "Grid.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Grid grid;
    grid.resize(700, 700);
    grid.show();

    return app.exec();
}
