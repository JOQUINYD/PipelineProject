#ifndef DATABASE_H
#define DATABASE_H


#include "Producto.h"
#include "TemplateQueue.h"
#include "EtapaConf.h"

struct DataBase{
    int cantEtapas;
    int unidadTiempo;
    int maxRetrasoDes;
    int maxRetrasoCor;
    int tiempoTrans;
    QList<Queue<Producto*>*> colasDeEtapas;
    QList<EtapaConf*> etapas;
    QList<Producto*> productosIngresados;
    QList<QListWidget*> lwEtapas;
    QList<QListWidget*> lwEtapasError;
    QString productName;
    bool produccion;
    bool running;

    DataBase(int _cantEtapas, int _unidadTiempo, int _maxRetrasoDes, int _maxRetrasoCor, int margenDeError, QString _productName, int maxCola, int _probDesecho){

        cantEtapas = _cantEtapas;
        unidadTiempo = _unidadTiempo;
        maxRetrasoDes = _maxRetrasoDes;
        maxRetrasoCor = _maxRetrasoCor;
        productName = _productName;
        produccion = true;
        running = true;
        tiempoTrans = 0;

        for(int i = 0; i < cantEtapas; i++){
            Queue<Producto*> * tmp = new Queue<Producto*>();
            colasDeEtapas.append(tmp);
            EtapaConf * etapa = new EtapaConf(i,margenDeError,"Etapa #" + QString::number(i+1),maxCola, _probDesecho);
            etapas.append(etapa);
        }
    }

    void changeEtapaName(int i, QString _name);
    void changeEtapaProbError(int i, int _probError);
    void changeEtapaMaxCola(int i, int max);
    void changeEtapaProbDesecho(int i, int _probDes);
    void detenerPorDesecho(int numEtapa, int idProduct);
    void reanudarPorDesecho(int numEtapa, int retraso);
    int getProductosFinalizados(int tope);
    int getProductosError(int tope);
    int getProductosDetenidos();
};

#endif // DATABASE_H
