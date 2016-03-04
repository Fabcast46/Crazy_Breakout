#include "menuwindow.h"
#include "ui_menuwindow.h"


menuWindow::menuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
}

menuWindow::~menuWindow()
{
    delete ui;
}

void menuWindow::on_btnJugar_clicked()
{
    Game* g = new Game();
    g->show();
    g->start();

}



void menuWindow::on_btnSalir_clicked()
{
    this->close();


}
