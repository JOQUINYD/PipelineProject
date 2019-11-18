#ifndef PRODUCTO_H
#define PRODUCTO_H

#endif // PRODUCTO_H

#include "Includes.h"

struct Producto{
    int cantPartes;
    int parteActual;
    QList<bool> partes;
    QList<QString> historialErrores;
};
