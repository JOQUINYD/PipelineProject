#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent, DataBase * _dataBase) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    dataBase = _dataBase;
    ui->spSelecEtapa->setMaximum(dataBase->cantEtapas);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_btnSelecEtapa_clicked()
{
    ventanasEtapas.at(ui->spSelecEtapa->value()-1)->show();
}
