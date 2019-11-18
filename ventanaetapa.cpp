#include "ventanaetapa.h"
#include "ui_ventanaetapa.h"

VentanaEtapa::VentanaEtapa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaEtapa)
{
    ui->setupUi(this);
}

VentanaEtapa::~VentanaEtapa()
{
    delete ui;
}
