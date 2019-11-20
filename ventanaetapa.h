#ifndef VENTANAETAPA_H
#define VENTANAETAPA_H

#include <QMainWindow>
#include "DataBase.h"

namespace Ui {
class VentanaEtapa;
}

class VentanaEtapa : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaEtapa(QWidget *parent = nullptr, EtapaConf * _myEtapa = nullptr, DataBase * _dataBase = nullptr);
    ~VentanaEtapa();

private slots:
    void on_btnDetener_clicked();

private:
    Ui::VentanaEtapa *ui;
    EtapaConf * myEtapa;
    DataBase * dataBase;
};

#endif // VENTANAETAPA_H
