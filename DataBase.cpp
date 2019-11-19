#include "DataBase.h"

void DataBase::changeEtapaName(int i, QString _name){
    this->etapas.takeAt(i)->setName(_name);
}

void DataBase::changeEtapaProbError(int i, int _probError){
    this->etapas.takeAt(i)->setProbError(_probError);
}

void DataBase::changeEtapaMaxCola(int i, int max){
    this->etapas.takeAt(i)->setMaxCola(max);
}
