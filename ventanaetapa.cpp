#include "ventanaetapa.h"
#include "ui_ventanaetapa.h"

VentanaEtapa::VentanaEtapa(QWidget *parent, EtapaConf * _myEtapa, DataBase * _dataBase) :
    QMainWindow(parent),
    ui(new Ui::VentanaEtapa)
{
    ui->setupUi(this);
    dataBase = _dataBase;
    dataBase->lwEtapas.append(ui->lwProductos);
    this->myEtapa = _myEtapa;
    this->setWindowTitle("Etapa " + QString::number(myEtapa->id+1) + " - " + myEtapa->name);
}

VentanaEtapa::~VentanaEtapa()
{
    delete ui;
}
