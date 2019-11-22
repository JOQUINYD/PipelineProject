#include "threadproduccion.h"

ThreadProduccion::ThreadProduccion()
{

}

void ThreadProduccion::__init__(DataBase *_dataBase){
    this->dataBase = _dataBase;
    this->myQueue = new Queue<Producto*>();
    setNextEtapa();
    setNextQueue();
}

void ThreadProduccion::setNextEtapa(){
    nextEtapa = dataBase->etapas.at(0);
}

void ThreadProduccion::setNextQueue(){
    nextQueue = dataBase->colasDeEtapas.at(0);
}


void ThreadProduccion::run(){
    int cantProd = 0;
    int productId = 1;
    while(true){
        while (dataBase->produccion) {
            //qDebug() << "Soy produccion";
            if(cantProd < 200){
                cantProd++;
                productId++;
                Producto * newProduct = new Producto(dataBase->cantEtapas,productId);
                dataBase->productosIngresados.append(newProduct);
                myQueue->queue(newProduct);

                if(!myQueue->isEmpty() && nextEtapa->enCola < nextEtapa->maxCola){
                    nextEtapa->incEnCola();
                    nextQueue->mutex.lock();
                    Producto * prodEnv = myQueue->dequeue();
                    prodEnv->partes.at(0)->espera = true;
                    nextQueue->queue(prodEnv);
                    nextQueue->mutex.unlock();
                    cantProd--;
                }
            }
            msleep(dataBase->unidadTiempo);
        }
        msleep(100);
    }
}
