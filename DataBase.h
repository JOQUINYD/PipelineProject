#ifndef DATABASE_H
#define DATABASE_H

#endif // DATABASE_H

#include "Producto.h"
#include "TemplateQueue.h"
#include "EtapaConf.h"

struct DataBase{
    int cantEtapas;
    int unidadTiempo;
    int maxRetrasoDes;
    int maxRetrasoCor;
    QList<Queue<Producto*>*> colasDeEtapas;
    QList<EtapaConf*> etapas;
    QList<Producto*> productosIngresados;
    QString productName;

    DataBase(int _cantEtapas, int _unidadTiempo, int _maxRetrasoDes, int _maxRetrasoCor, int margenDeError, QString _productName, int maxCola){

        cantEtapas = _cantEtapas;
        unidadTiempo = _unidadTiempo;
        maxRetrasoDes = _maxRetrasoDes;
        maxRetrasoCor = _maxRetrasoCor;
        productName = _productName;

        for(int i = 0; i < cantEtapas; i++){
            Queue<Producto*> * tmp = new Queue<Producto*>();
            colasDeEtapas.append(tmp);
            EtapaConf * etapa = new EtapaConf(i,margenDeError,"Etapa #" + QString::number(i+1),maxCola);
            etapas.append(etapa);
        }
    }

    void changeEtapaName(int i, QString _name);
    void changeEtapaProbError(int i, int _probError);
    void changeEtapaMaxCola(int i, int max);
};
