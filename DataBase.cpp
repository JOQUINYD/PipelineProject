#include "DataBase.h"

void DataBase::changeEtapaName(int i, QString _name){
    this->etapas.at(i)->setName(_name);
}

void DataBase::changeEtapaProbError(int i, int _probError){
    this->etapas.at(i)->setProbError(_probError);
}

void DataBase::changeEtapaMaxCola(int i, int max){
    this->etapas.at(i)->setMaxCola(max);
}

void DataBase::detenerPorDesecho(int numEtapa, int idProduct){
    for(int i = numEtapa+1; i < cantEtapas; i++){
        EtapaConf * tmp = etapas.at(i);
        if(tmp->pause){
            break;
        }
        tmp->mutex.lock();
        if(!tmp->detenido){
            tmp->setDetenido(true);
            lwEtapasError.at(i)->addItem("Etapa detenida por desecho de " + productName + " #" + QString::number(idProduct));
            tmp->setDesecho(true);
        }
        tmp->mutex.unlock();
    }
}

void DataBase::reanudarPorDesecho(int numEtapa, int retraso){
    for(int i = numEtapa; i < cantEtapas; i++){
        EtapaConf * tmp = etapas.at(i);
        if(tmp->pause){
            break;
        }
        tmp->mutex.lock();
        if(tmp->detenido){
            lwEtapasError.at(i)->addItem("Etapa reanudada luego de " + QString::number(retraso) + " unidades de tiempo");
            tmp->setDetenido(false);
            tmp->setDesecho(false);
        }
        tmp->mutex.unlock();
    }
}

int DataBase::getProductosFinalizados(int tope){
    int cant = 0;
    for (int i = 0; i < tope; i++) {
        if(productosIngresados.at(i)->terminado){
            cant++;
        }
    }
    return cant;
}

int DataBase::getProductosError(int tope){
    int cant = 0;
    for (int i = 0; i < tope; i++) {
        if(productosIngresados.at(i)->conError){
            cant++;
        }
    }
    return cant;
}

int DataBase::getProductosDetenidos(){
    int cant = 0;
    for(int i = 0; i < cantEtapas; i++){
        cant += etapas.at(i)->enCola;
    }
    return cant;
}
