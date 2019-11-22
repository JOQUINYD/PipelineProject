#ifndef ETAPACONF_H
#define ETAPACONF_H

#include "Includes.h"

struct EtapaConf{
    bool running;
    bool detenido;
    bool pause;
    bool correcion;
    bool desecho;
    QString name;
    int id;
    int probError;
    int maxCola;
    int enCola;
    std::mutex mutex;

    EtapaConf(int _id, int _probError, QString _name, int _maxCola){
        this->id = _id;
        this->probError = _probError;
        this->name = _name;
        running = true;
        detenido = false;
        correcion = false;
        desecho = false;
        pause = false;
        maxCola = _maxCola;
        enCola = 0;
    }

    void setName(QString _name);
    void setProbError(int _probError);
    void setDetenido(bool _detenido);
    void setCorrecion(bool _correcion);
    void setDesecho(bool _desecho);
    void setMaxCola(int max);
    void incEnCola();
    void decEnCola();
};

#endif // ETAPACONF_H
