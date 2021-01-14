#include "MatrixMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixMainWindow w;
    w.show();

    return a.exec();
}
