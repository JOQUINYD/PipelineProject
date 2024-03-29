#include "ThreadEtapa.h"
extern "C"{
    int _test1(int, int, int);
    int _test2(int, int, int);
    //void _start(void);
    int _randomGenerator(int min, int max);
    int _determProb(int prob, int margen);
}

ThreadEtapa::ThreadEtapa(){

}

void ThreadEtapa::__init__(DataBase *_dataBase, EtapaConf * _etapa, QListWidget * _lwProducts){
    dataBase = _dataBase;
    etapa = _etapa;
    queue = dataBase->colasDeEtapas.at(etapa->id);
    lwProducts = _lwProducts;
    setNextQueue();
    setNextEtapa();
}

void ThreadEtapa::run(){
    Producto * prodAc = nullptr;
    while(dataBase->running){
        while(!etapa->detenido && !etapa->pause){
            //qDebug() << "Soy etapa " << etapa->id+1;

            if(etapa->probError != 100 && !queue->isEmpty()){

                if(prodAc == nullptr){
                    queue->mutex.lock();
                    prodAc = queue->dequeue();
                    queue->mutex.unlock();
                    prodAc->partes.at(etapa->id)->espera = false;
                    etapa->decEnCola();
                    //qDebug() << "Producto #" + QString::number(prodAc->id) + " iniciando etapa";
                    lwProducts->addItem(dataBase->productName + " #" + QString::number(prodAc->id) + " iniciando etapa");
                }
                if(prodAc != nullptr){
                    if(etapa->probError > 0){
                        int probaError = _randomGenerator(0,100);
                        int ocurreError = _determProb(probaError,etapa->probError);

                        if(ocurreError == 1){

                            prodAc->conError = true;
                            int probTipoError = _randomGenerator(0,100);
                            int tipo = _determProb(probTipoError,etapa->probDesecho);

                            // tipo != 1 significa que se corregira el producto
                            if(tipo != 1){
                                int retraso = _randomGenerator(1,dataBase->maxRetrasoCor);
                                retraso *= dataBase->unidadTiempo;
                                lwProducts->addItem("Etapa detenida por correcion de " + dataBase->productName + " #" + QString::number(prodAc->id));
                                msleep(retraso);
                                prodAc->partes.at(etapa->id)->error = true;
                                prodAc->partes.at(etapa->id)->corregido = true;
                            }
                            // tipo == 1 significa que se desecha el producto
                            else{
                                int retraso = _randomGenerator(1,dataBase->maxRetrasoDes);
                                int ret = retraso;
                                retraso *= dataBase->unidadTiempo;
                                dataBase->detenerPorDesecho(etapa->id, prodAc->id);
                                lwProducts->addItem("Etapa detenida por desecho de " + dataBase->productName + " #" + QString::number(prodAc->id));
                                msleep(retraso);
                                dataBase->reanudarPorDesecho(etapa->id,ret);
                                prodAc->partes.at(etapa->id)->error = true;
                                prodAc->partes.at(etapa->id)->desechado = true;
                                prodAc = nullptr;
                            }
                        }
                    }
                }
                if(prodAc != nullptr){
                    if(nextEtapa != nullptr){
                        if(nextEtapa->enCola < nextEtapa->maxCola){
                            lwProducts->addItem(dataBase->productName + " #" + QString::number(prodAc->id) + " hacia siguiente etapa");
                            nextQueue->mutex.lock();
                            nextEtapa->incEnCola();
                            prodAc->partes.at(etapa->id)->exito = true;
                            prodAc->partes.at(nextEtapa->id)->espera = true;
                            nextQueue->queue(prodAc);
                            nextQueue->mutex.unlock();
                            prodAc = nullptr;
                        }
                    }
                    else{
                        prodAc->terminado = true;
                        prodAc->partes.at(etapa->id)->exito = true;
                        lwProducts->addItem(dataBase->productName + " #" + QString::number(prodAc->id) + " terminado de producir");
                        prodAc = nullptr;
                    }
                }
            }
            msleep(dataBase->unidadTiempo);
        }
        msleep(100);
    }
}

void ThreadEtapa::setNextQueue(){
    if(etapa->id+1 < dataBase->cantEtapas){
        this->nextQueue = dataBase->colasDeEtapas.at(etapa->id+1);
    }
    else{
        this->nextQueue = nullptr;
    }
}

void ThreadEtapa::setNextEtapa(){
    if(etapa->id+1 < dataBase->cantEtapas){
        this->nextEtapa = dataBase->etapas.at(etapa->id+1);
    }
    else{
        this->nextEtapa = nullptr;
    }
}
