#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->dataBase = new DataBase(5,1000,1,1,20,"Producto general");
    ui->spSelecEtapa->setMaximum(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnStart_clicked()
{
    // inicializar los threads y despues inicializar el thread que crea productos
    VentanaPrincipal * v =  new VentanaPrincipal(this);
    v->show();
}

void MainWindow::on_btnConfirm_clicked()
{
    int cantEtapas = ui->spCantEtapas->value();
    int unidad = ui->spUnidadTiempo->value();
    int maxRetCor= ui->spMaxRetrasoCor->value();
    int maxRetDes = ui->spMaxRetrasoDes->value();
    int margenError = ui->spErrorGlobal->value();
    QString productName = ui->txtProductName->text();
    this->dataBase = new DataBase(cantEtapas,unidad,maxRetDes,maxRetCor,margenError,productName);
    ui->spSelecEtapa->setMaximum(cantEtapas);
}

void MainWindow::on_btnChangeEtapaName_clicked()
{
    QString etapaName = ui->txtEtapaNewName->text();
    int numEtapa = ui->spSelecEtapa->value() - 1;
    this->dataBase->changeEtapaName(numEtapa,etapaName);
}

void MainWindow::on_btnModMargen_clicked()
{
    int numEtapa = ui->spSelecEtapa->value();
    int margen = ui->spMargenErrorLocal->value();
    this->dataBase->changeEtapaProbError(numEtapa,margen);
}

void MainWindow::on_btnModMaxCola_clicked()
{
    int numEtapa = ui->spSelecEtapa->value();
    int max = ui->spMaxColaLoc->value();
    this->dataBase->changeEtapaMaxCola(numEtapa,max);
}
