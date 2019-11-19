#include "mainwindow.h"
#include "QDebug"
#include <QApplication>

extern "C"{
    int _test1(int, int, int);
    int _test2(int, int, int);
    //void _start(void);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << "Hola Mundo";

    int x = 125, y = 300;
    int value;

    value = _test1(x, y, 5);
    value = _test2(x, y, 5);
    //_start();
    qDebug() << "Resultado = " << value;


    return a.exec();
}
