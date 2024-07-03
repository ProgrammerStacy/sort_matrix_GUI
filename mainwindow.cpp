#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rowItem = 0;
    columnItem = 0;
    inputSize = new QLineEdit;
    inputNum = new QLineEdit;
    bSize = new QPushButton;
    bNum = new QPushButton;
    connect(bSize, SIGNAL(clicked()), this, SLOT(bSize_clicked()));
    connect(bNum, SIGNAL(clicked()), this, SLOT(bNum_clicked()));
    inputNum->show();
    bSize->show();
    bNum-> show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::bSize_clicked()
{
    int n = inputSize->text().toInt();
    inputTable = new QTableWidget(n, n);
    inputTable->show();
    mtrx = new Matrix(n);
}
void MainWindow::bNum_clicked()
{

    if (rowItem <= inputTable->rowCount())
    {
        QTableWidgetItem* temp = new QTableWidgetItem;
        temp->setText(inputNum->text());
        inputTable->setItem(rowItem, columnItem, temp);
        mtrx->inputmatr_qt(rowItem, columnItem, inputNum->text().toInt());
        if (rowItem == inputTable->rowCount())
        {
            mtrx->sort_matr();
            mtrx->obnulenie();
            fill_outputTable();
        }
        rowItem++;
        columnItem++;
        delete temp;
    }

}
void MainWindow::fill_outputTable()
{
    outputTable = new QTableWidget(rowItem, columnItem);
    QTableWidgetItem* temp = new QTableWidgetItem;
    for (int i = 0; i <= rowItem; i++)
    {
        for (int j  = 0; j <= columnItem; j++)
        {
            temp->setText(QString::number(mtrx->outputmatr_qt(i, j)));
            outputTable->setItem(i,j, temp);
        }
    }
    outputTable->show();
    delete temp;
}
