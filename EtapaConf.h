#ifndef ETAPACONF_H
#define ETAPACONF_H

#endif // ETAPACONF_H
#include "Includes.h"

struct EtapaConf{
    bool running;
    bool detenido;
    bool error;
    bool desecho;
    QString name;
    int id;
    int probError;
    int maxCola;

    EtapaConf(int _id, int _probError, QString _name, int _maxCola){
        this->id = _id;
        this->probError = _probError;
        this->name = _name;
        running = true;
        detenido = false;
        error = false;
        desecho = false;
        maxCola = _maxCola;
    }

    void setName(QString _name);
    void setProbError(int _probError);
    void setDetenido(bool _detenido);
    void setError(bool _error);
    void setDesecho(bool _desecho);
    void setMaxCola(int max);
};
