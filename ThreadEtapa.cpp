#include "ThreadEtapa.h"

void ThreadEtapa::__init__(DataBase *_dataBase, EtapaConf * _etapa, QListWidget * _lwProducts){
    dataBase = _dataBase;
    etapa = _etapa;
    queue = dataBase->colasDeEtapas.takeAt(etapa->id);
    lwProducts = _lwProducts;
    setNextQueue();
    setNextEtapa();
}

void ThreadEtapa::run(){
    while(etapa->running){
        while(!etapa->detenido){
            if(!queue->isEmpty()){

                queue->mutex.lock();
                Producto * prodAc = queue->dequeue();
                queue->mutex.unlock();


            }
        }
        msleep(dataBase->unidadTiempo);
    }
}

void ThreadEtapa::setNextQueue(){
    if(etapa->id+1 < dataBase->cantEtapas){
        this->nextQueue = dataBase->colasDeEtapas.takeAt(etapa->id+1);
    }
    else{
        this->nextQueue = nullptr;
    }
}

void ThreadEtapa::setNextEtapa(){
    if(etapa->id+1 < dataBase->cantEtapas){
        this->nextEtapa = dataBase->etapas.takeAt(etapa->id+1);
    }
    else{
        this->nextEtapa = nullptr;
    }
}
