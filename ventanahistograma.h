#ifndef VENTANAHISTOGRAMA_H
#define VENTANAHISTOGRAMA_H

#include <QMainWindow>
#include "DataBase.h"
#include "QTableWidgetItem"

namespace Ui {
class VentanaHistograma;
}

class VentanaHistograma : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaHistograma(QWidget *parent = nullptr, DataBase * _dataBase = nullptr);
    ~VentanaHistograma();
    void agregarColumnas();
    void agregarFilas();
    void actualizarColumnas();
    void actualizarFilasProductos();
    void ponerColorEtapa(int i, int j);
    void ponerColorProductos(int cant);
    void ponerColorProducto(int i, int j, Producto * producto);
    void agregarNuevasFilas();

private slots:

private:
    Ui::VentanaHistograma *ui;
    DataBase * dataBase;
    int cantFilas = 0;
};

#endif // VENTANAHISTOGRAMA_H
