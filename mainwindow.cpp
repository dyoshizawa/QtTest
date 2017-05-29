#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    ui->lineEdit->setText("push button");
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor color(255, 0,0);
    ui->textEdit->setTextBackgroundColor(color);
    ui->textEdit->setText("push button");
}
