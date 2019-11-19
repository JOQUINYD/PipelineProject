
#include "EtapaConf.h"

void EtapaConf::setName(QString _name){
    this->name = _name;
}

void EtapaConf::setError(bool _error){
    this->error = _error;
}

void EtapaConf::setDesecho(bool _desecho){
    this->desecho = _desecho;
}

void EtapaConf::setDetenido(bool _detenido){
    this->detenido = _detenido;
}

void EtapaConf::setProbError(int _probError){
    this->probError = _probError;
}

void EtapaConf::setMaxCola(int max){
    this->maxCola = max;
}
