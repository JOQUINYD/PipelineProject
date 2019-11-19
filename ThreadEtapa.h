#ifndef THREADETAPA_H
#define THREADETAPA_H

#endif // THREADETAPA_H
#include "Includes.h"
#include "DataBase.h"

class ThreadEtapa : public QThread
{
public:
    DataBase * dataBase;
    Queue<Producto*> * queue;
    Queue<Producto*> * nextQueue;
    EtapaConf * etapa;
    EtapaConf * nextEtapa;
    QListWidget * lwProducts;

    ThreadEtapa();
    void __init__(DataBase * _dataBase, EtapaConf * _etapa, QListWidget * _lwProducts);
    void run();
    void setNextQueue();
    void setNextEtapa();
};
