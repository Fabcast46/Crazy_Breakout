#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class menuWindow;
}

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = 0);
    ~menuWindow();

private slots:
    void on_btnJugar_clicked();

    void on_btnSalir_clicked();

private:
    Ui::menuWindow *ui;
};

#endif // MENUWINDOW_H
