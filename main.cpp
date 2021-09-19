#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    w.setWindowTitle("RGB Color Selector");
    w.show();
    return a.exec();
}
