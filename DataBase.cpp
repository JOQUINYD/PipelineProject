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
    for(int i = numEtapa; i < cantEtapas; i++){
        EtapaConf * tmp = etapas.at(i);
        tmp->setDetenido(true);
        lwEtapas.at(i)->addItem("Etapa detenida por desecho de " + productName + " #" + QString::number(idProduct));
        tmp->setDesecho(true);
    }
}

void DataBase::reanudarPorDesecho(int numEtapa, int retraso){
    for(int i = numEtapa; i < cantEtapas; i++){
        EtapaConf * tmp = etapas.at(i);
        lwEtapas.at(i)->addItem("Etapa reanudada luego de " + QString::number(retraso) + " unidades de tiempo");
        tmp->setDetenido(false);
        tmp->setDesecho(false);
    }
}
