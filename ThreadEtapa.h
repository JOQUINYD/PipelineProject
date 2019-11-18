#ifndef THREADETAPA_H
#define THREADETAPA_H

#endif // THREADETAPA_H
#include "Includes.h"
#include "DataBase.h"

class ThreadEtapa : public QThread
{
public:
    DataBase * dataBase;
    int numEtapa;

    ThreadEtapa();
    void __init__(DataBase * _dataBase, int _numEtapa);
    void run();
    void asignarClientes();
    void printOcupadas(int cantMesas);
};
