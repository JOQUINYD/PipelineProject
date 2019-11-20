#include "ventanahistograma.h"
#include "ui_ventanahistograma.h"

VentanaHistograma::VentanaHistograma(QWidget *parent, DataBase * _dataBase) :
    QMainWindow(parent),
    ui(new Ui::VentanaHistograma)
{
    ui->setupUi(this);
    dataBase = _dataBase;
    ui->twHistogram->setRowCount(101);
    agregarColumnas();
    agregarFilas();
    /*
    QStringList titulos;
    titulos.append("Etapa 1");
    titulos << "Etapa 2" << "Etapa 3" << "Etapa 4" << "Etapa 5" << "Etapa 6" << "Etapa 7" << "Etapa 8" << "Etapa 9" << "Etapa 10" << "Etapa 11" << "Etapa 12" << "Etapa 13" << "Etapa 14" << "Etapa 15";
    ui->twHistogram->setColumnCount(15);
    ui->twHistogram->setHorizontalHeaderLabels(titulos);
    ui->twHistogram->insertRow(0);
    QTableWidgetItem * item = new QTableWidgetItem();
    QColor * color = new QColor();
    color->red();
    item->setBackgroundColor(*color);
    ui->twHistogram->setItem(0,0,item);
    */

}

VentanaHistograma::~VentanaHistograma()
{
    delete ui;
}

void VentanaHistograma::agregarColumnas(){
    ui->twHistogram->setColumnCount(dataBase->cantEtapas);
    QStringList titulos;
    for (int i = 0; i < dataBase->cantEtapas; i++) {
        titulos.append(" ");
        QTableWidgetItem * item = new QTableWidgetItem("Etapa " + QString::number(i+1));
        //ui->twHistogram->setHorizontalHeaderItem(i,item->setText("Etapa " + QString::number(i+1))));
        ui->twHistogram->setItem(0,i,item);
        //ui->twHistogram->setHorizontalHeaderItem(i,item);
        ponerColorEtapa(0, i);
    }
    ui->twHistogram->setHorizontalHeaderLabels(titulos);
}

void VentanaHistograma::agregarFilas(){
    cantFilas = 101;
    int cant = dataBase->productosIngresados.size();
    for(int i = 1; i < cantFilas+1; i++){
        for (int j = 0; j < dataBase->cantEtapas; j++) {
            QTableWidgetItem * item = new QTableWidgetItem();
            ui->twHistogram->setItem(i,j,item);
            if(i-1 < cant){
                Producto * producto = dataBase->productosIngresados.at(i-1);
                ponerColorProducto(i, j, producto);
            }
        }
    }
}

void VentanaHistograma::agregarNuevasFilas(){
    int cantProd = dataBase->productosIngresados.size();
    if(cantProd > cantFilas){
        int lastIndex = cantFilas;
        cantFilas = cantProd;
        for(int i = lastIndex; i < cantFilas; i++){
            ui->twHistogram->insertRow(ui->twHistogram->rowCount());
            for (int j = 0; j < dataBase->cantEtapas; j++) {
                QTableWidgetItem * item = new QTableWidgetItem();
                ui->twHistogram->setItem(i,j,item);
                Producto * producto = dataBase->productosIngresados.at(i-1);
                ponerColorProducto(i, j, producto);
            }
        }
    }
}

void VentanaHistograma::actualizarColumnas(){
    for (int i = 0; i < dataBase->cantEtapas; i++) {
        ponerColorEtapa(0,i);
        //ui->twHistogram->update();
    }
}

void VentanaHistograma::ponerColorEtapa(int i, int j){
    EtapaConf * tmpEtapa = dataBase->etapas.at(j);
    if(tmpEtapa->detenido){
        ui->twHistogram->item(i,j)->setBackgroundColor(QColor(206,92,0));
    }
    else if(tmpEtapa->pause || tmpEtapa->probError == 100){
        ui->twHistogram->item(i,j)->setBackgroundColor(QColor(164,0,0));
    }
    else{
        ui->twHistogram->item(i,j)->setBackgroundColor(QColor(38,118,7));
    }
}

void VentanaHistograma::ponerColorProducto(int i, int j, Producto * producto){
    EstadoProducto * estado = producto->partes.at(j);
    if(!estado->pintado){
        if(estado->error){
            if(estado->desechado){
                ui->twHistogram->item(i,j)->setBackgroundColor(QColor(204,0,0));
                estado->pintado = true;
            }
            else{
                ui->twHistogram->item(i,j)->setBackgroundColor(QColor(245,121,0));
                estado->pintado = true;
            }
        }
        else{
            if(estado->espera){
                ui->twHistogram->item(i,j)->setBackgroundColor(QColor(52,101,164));
            }
            else if(estado->exito){
                ui->twHistogram->item(i,j)->setBackgroundColor(QColor(78,154,6));
                estado->pintado = true;
            }
        }
    }
}

void VentanaHistograma::actualizarFilasProductos(){
    int cant = dataBase->productosIngresados.size();
    if(cant > 0){
        if(cant > cantFilas)
            cant = cantFilas;
        for(int i = 0; i < cant-1; i++){
            for(int j = 0; j < dataBase->cantEtapas; j++){
                Producto * producto = dataBase->productosIngresados.at(i);
                ponerColorProducto(i+1,j,producto);
            }
        }
    }
}




void VentanaHistograma::on_toolButton_clicked()
{
    actualizarColumnas();
}
