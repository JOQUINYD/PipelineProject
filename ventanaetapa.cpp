#include "ventanaetapa.h"
#include "ui_ventanaetapa.h"

VentanaEtapa::VentanaEtapa(QWidget *parent, EtapaConf * _myEtapa, DataBase * _dataBase) :
    QMainWindow(parent),
    ui(new Ui::VentanaEtapa)
{
    ui->setupUi(this);
    dataBase = _dataBase;
    dataBase->lwEtapas.append(ui->lwProductos);
    dataBase->lwEtapasError.append(ui->lwErrores);
    this->myEtapa = _myEtapa;
    this->setWindowTitle("Etapa " + QString::number(myEtapa->id+1) + " - " + myEtapa->name);
    ui->btnDetener->setCheckable(true);
}

VentanaEtapa::~VentanaEtapa()
{
    delete ui;
}

void VentanaEtapa::on_btnDetener_clicked()
{
    this->myEtapa->pause = !this->myEtapa->pause;
}
