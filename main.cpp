#include "mainwindow.h"
#include "QDebug"
#include <QApplication>

extern "C"{
    int _test1(int, int, int);
    int _test2(int, int, int);
    //void _start(void);
    int _randomGenerator(int min, int max);
    int _determProb(int prob, int margen);
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
    int ran = _randomGenerator(0,100);
    qDebug() << "Random = " << ran;
    int ocurre = _determProb(ran,75);
    if(ocurre == 1){
        qDebug() << "Ocurre";
    }
    else if(ocurre == 0){
        qDebug() << "No ocurre";
    }
    return a.exec();
}
