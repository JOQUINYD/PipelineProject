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

    EtapaConf(int _id, int _probError, QString _name){
        this->id = _id;
        this->probError = _probError;
        this->name = _name;
        running = true;
        detenido = false;
        error = false;
        desecho = false;
    }

    void setName(QString _name);
    void setProbError(int _probError);
    void setDetenido(bool _detenido);
    void setError(bool _error);
    void setDesecho(bool _desecho);
};
