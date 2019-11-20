#ifndef ESTADOPRODUCTO_H
#define ESTADOPRODUCTO_H


struct EstadoProducto{
    bool error;
    bool desechado;
    bool corregido;
    bool espera;
    bool exito;
    bool pintado;
    int etapaOcurrio;

    EstadoProducto(int _etapaOcurrio){
        error = corregido = desechado = espera = exito = pintado = false;
        etapaOcurrio = _etapaOcurrio;
    }
};
#endif // ESTADOPRODUCTO_H
