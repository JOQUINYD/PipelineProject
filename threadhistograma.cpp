#include "threadhistograma.h"

ThreadHistograma::ThreadHistograma()
{

}

void ThreadHistograma::__init__(DataBase *_dataBase, VentanaHistograma * _histograma){
    dataBase = _dataBase;
    histograma = _histograma;
}

void ThreadHistograma::run(){
    while (dataBase->running) {
        msleep(dataBase->unidadTiempo);
        histograma->actualizarColumnas();
        histograma->agregarNuevasFilas();
        histograma->actualizarFilasProductos();

    }
}
