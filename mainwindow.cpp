#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->dataBase = new DataBase(5,1000,1,1,20,"Producto general",100, 50);
    ui->spSelecEtapa->setMaximum(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnStart_clicked()
{
    // inicializar los threads y despues inicializar el thread que crea productos
    QList<VentanaEtapa*> etapasView;
    for(int i = 0; i < dataBase->cantEtapas; i++){
        EtapaConf * tmp = dataBase->etapas.at(i);
        VentanaEtapa * ventana = new VentanaEtapa(this, tmp, dataBase);
        ThreadEtapa * thread = new ThreadEtapa();
        thread->__init__(dataBase,tmp, dataBase->lwEtapas.at(i));
        thread->start();
        etapasView.append(ventana);
    }
    VentanaPrincipal * v =  new VentanaPrincipal(this,dataBase);
    v->ventanasEtapas = etapasView;
    ThreadProduccion * threadProd = new ThreadProduccion();
    ThreadContador * threadCont = new ThreadContador();
    threadCont->__init__(dataBase);
    threadProd->__init__(dataBase);
    threadCont->start();
    threadProd->start();
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
    int maxCola = ui->spMaxColaGlob->value();
    int probDesecho = ui->spProbDesCor->value();

    this->dataBase = new DataBase(cantEtapas,unidad,maxRetDes,maxRetCor,margenError,productName,maxCola,probDesecho);
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
    int numEtapa = ui->spSelecEtapa->value() - 1;
    int margen = ui->spMargenErrorLocal->value();
    this->dataBase->changeEtapaProbError(numEtapa,margen);
}

void MainWindow::on_btnModMaxCola_clicked()
{
    int numEtapa = ui->spSelecEtapa->value() - 1;
    int max = ui->spMaxColaLoc->value();
    this->dataBase->changeEtapaMaxCola(numEtapa,max);
}

void MainWindow::on_spSelecEtapa_valueChanged(int arg1)
{
    EtapaConf * tmp = dataBase->etapas.at(ui->spSelecEtapa->value()-1);
    ui->txtEtapaNewName->setText(tmp->name);
    ui->spMargenErrorLocal->setValue(tmp->probError);
    ui->spMaxColaLoc->setValue(tmp->maxCola);
}



void MainWindow::on_btnChangeProbDesCor_clicked()
{
    int numEtapa = ui->spSelecEtapa->value() - 1;
    int probDes = ui->spProbDesCorLocal->value();
    this->dataBase->changeEtapaProbDesecho(numEtapa,probDes);
}
