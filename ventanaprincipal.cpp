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

void VentanaPrincipal::on_btnGenerarRep_clicked()
{
    int tiempo = dataBase->tiempoTrans;
    int maxProd = dataBase->productosIngresados.size();
    int prodFin = dataBase->getProductosFinalizados(maxProd);
    int prodError = dataBase->getProductosError(maxProd);
    int prodDet = dataBase->getProductosDetenidos();
    ui->txtUnidades->setText(QString::number(tiempo));
    ui->txtProductsFin->setText(QString::number(prodFin));
    ui->txtProductsError->setText(QString::number(prodError));
    ui->txtProductsDeten->setText(QString::number(prodDet));
}
