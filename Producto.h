#ifndef PRODUCTO_H
#define PRODUCTO_H


#include "Includes.h"
#include "EstadoProducto.h"

struct Producto{
    int cantPartes;
    int parteActual;
    bool terminado;
    int id;
    bool conError;
    QList<EstadoProducto*> partes;

    Producto(int _cantPartes, int _id){
        id = _id;
        conError = terminado = false;
        cantPartes = _cantPartes;
        parteActual = 0;
        for (int i = 0; i < cantPartes; i++) {
            partes.append(new EstadoProducto(i));
        }
    }
};

#endif // PRODUCTO_H
