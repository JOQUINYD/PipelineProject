#include "threadcontador.h"

ThreadContador::ThreadContador()
{

}

void ThreadContador::__init__(DataBase * _dataBase){
    dataBase = _dataBase;
}
void ThreadContador::run(){
    while(dataBase->running){
        msleep(dataBase->unidadTiempo);
        dataBase->tiempoTrans++;
    }
}
