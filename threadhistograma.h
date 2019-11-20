#ifndef THREADHISTOGRAMA_H
#define THREADHISTOGRAMA_H

#include "DataBase.h"
#include "ventanahistograma.h"
#include "Includes.h"

class ThreadHistograma : public QThread
{
public:
    ThreadHistograma();
    DataBase * dataBase;
    VentanaHistograma * histograma;

    void __init__(DataBase * _dataBase, VentanaHistograma * _histograma);
    void run();
};

#endif // THREADHISTOGRAMA_H
