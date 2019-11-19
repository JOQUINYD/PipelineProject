#ifndef PRODUCTO_H
#define PRODUCTO_H

#endif // PRODUCTO_H

#include "Includes.h"
#include "EstadoProducto.h"

struct Producto{
    int cantPartes;
    int parteActual;
    QList<EstadoProducto*> partes;

    Producto(int _cantPartes){
        cantPartes = _cantPartes;
        parteActual = 0;
        for (int i = 0; i < cantPartes; i++) {
            partes.append(new EstadoProducto(i));
        }
    }
};
