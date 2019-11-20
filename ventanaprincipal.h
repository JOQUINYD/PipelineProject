#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "ventanaetapa.h"

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = nullptr, DataBase * _dataBase = nullptr);
    ~VentanaPrincipal();
    QList<VentanaEtapa*> ventanasEtapas;

private slots:
    void on_btnSelecEtapa_clicked();

    void on_btnGenerarRep_clicked();

private:
    Ui::VentanaPrincipal *ui;
    DataBase * dataBase;
};

#endif // VENTANAPRINCIPAL_H
