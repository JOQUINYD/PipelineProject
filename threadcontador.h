#ifndef THREADCONTADOR_H
#define THREADCONTADOR_H
#include "DataBase.h"
#include "Includes.h"

class ThreadContador : public QThread
{
public:
    ThreadContador();
    DataBase * dataBase;

    void __init__(DataBase * _dataBase);
    void run();
};


#endif // THREADCONTADOR_H
