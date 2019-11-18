#ifndef DATABASE_H
#define DATABASE_H

#endif // DATABASE_H

#include "Producto.h"
#include "TemplateQueue.h"

struct DataBase{
    int cantEtapas;
    QList<Queue<Producto*>*> colasDeEtapas;

    DataBase(int _cantEtapas){

        cantEtapas = _cantEtapas;

        for(int i = 0; i < cantEtapas; i++){
            Queue<Producto*> * tmp = new Queue<Producto*>();
            colasDeEtapas.append(tmp);
        }
    }
};
