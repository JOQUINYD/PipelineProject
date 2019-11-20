#ifndef THREADPRODUCCION_H
#define THREADPRODUCCION_H


#include "Includes.h"
#include "DataBase.h"

class ThreadProduccion : public QThread
{
public:
    DataBase * dataBase;
    Queue<Producto*> * myQueue;
    Queue<Producto*> * nextQueue;
    EtapaConf * nextEtapa;

    ThreadProduccion();
    void __init__(DataBase * _dataBase);
    void run();
    void setNextQueue();
    void setNextEtapa();
};
#endif // THREADPRODUCCION_H
