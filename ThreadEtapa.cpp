#include "ThreadEtapa.h"

void ThreadEtapa::__init__(DataBase *_dataBase, EtapaConf * _etapa){
    dataBase = _dataBase;
    etapa = _etapa;
    queue = dataBase->colasDeEtapas.takeAt(etapa->id);
}

void ThreadEtapa::run(){
    while(etapa->running){
        msleep(dataBase->unidadTiempo);
    }
}
