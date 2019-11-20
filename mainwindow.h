#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ventanaprincipal.h"
#include "ventanaetapa.h"
#include "ThreadEtapa.h"
#include "threadproduccion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

    void on_btnConfirm_clicked();

    void on_btnChangeEtapaName_clicked();

    void on_btnModMargen_clicked();

    void on_btnModMaxCola_clicked();

    void on_spSelecEtapa_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    DataBase * dataBase;
};
#endif // MAINWINDOW_H
