#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "ventanaetapa.h"
#include "threadhistograma.h"

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

    void on_btnHistograma_clicked();

private:
    Ui::VentanaPrincipal *ui;
    DataBase * dataBase;
    VentanaHistograma * histograma;
};

#endif // VENTANAPRINCIPAL_H
