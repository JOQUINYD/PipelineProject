#ifndef ESTADOPRODUCTO_H
#define ESTADOPRODUCTO_H

#endif // ESTADOPRODUCTO_H

struct EstadoProducto{
    bool error;
    bool desechado;
    bool corregido;
    int etapaOcurrio;

    EstadoProducto(int _etapaOcurrio){
        error = corregido = desechado = false;
        etapaOcurrio = _etapaOcurrio;
    }
};
