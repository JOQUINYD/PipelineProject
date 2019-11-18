#ifndef THREADETAPA_H
#define THREADETAPA_H

#endif // THREADETAPA_H
#include "Includes.h"
#include "DataBase.h"
#include "EtapaConf.h"

class ThreadEtapa : public QThread
{
public:
    DataBase * dataBase;
    Queue<Producto*> * queue;
    EtapaConf * etapa;

    ThreadEtapa();
    void __init__(DataBase * _dataBase, EtapaConf * _etapa);
    void run();
};
