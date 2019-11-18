#ifndef VENTANAETAPA_H
#define VENTANAETAPA_H

#include <QMainWindow>

namespace Ui {
class VentanaEtapa;
}

class VentanaEtapa : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaEtapa(QWidget *parent = nullptr);
    ~VentanaEtapa();

private:
    Ui::VentanaEtapa *ui;
};

#endif // VENTANAETAPA_H
