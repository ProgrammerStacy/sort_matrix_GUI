#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wgt = new QWidget();
    setCentralWidget(wgt);

    inputSize = new QLineEdit;
    bSize = new QPushButton;


    connect(bSize, SIGNAL(clicked()), this, SLOT(bSize_clicked()));


    first = new QHBoxLayout(wgt);
    left = new QVBoxLayout;
    first->addLayout(left);
    leftTop = new QHBoxLayout;
    left->addLayout(leftTop);
    leftTop->addWidget(inputSize);
    leftTop->addWidget(bSize);
    wgt->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::bSize_clicked()
{
    n = inputSize->text().toInt();
    inputTable = new QTableWidget(n, n);
    left->addWidget(inputTable);
    leftBottom = new QHBoxLayout;
    left->addLayout(leftBottom);
    bNum = new QPushButton;
    inputNum = new QLineEdit;
    leftBottom->addWidget(inputNum);
    leftBottom->addWidget(bNum);
    mtrx = new Matrix(n);
    connect(bNum, SIGNAL(clicked()), this, SLOT(bNum_clicked()));
}
void MainWindow::bNum_clicked()
{

    QTableWidgetItem* temp = new QTableWidgetItem;
    QString s;
    for (int i = 0; i < n; i++)
    {
        for (int j  = 0; j < n; j++)
        {
            if (inputTable->item(i,j) != 0)
            {
                temp = inputTable->item(i,j);
                mtrx->inputmatr_qt(i, j, temp->text().toInt());

            }
        }
    }
    delete temp;
    mtrx->sort_matr();
    mtrx->obnulenie();
    fill_outputTable();



}
void MainWindow::fill_outputTable()
{
    outputTable = new QTableWidget(n, n);
    QTableWidgetItem* temp = new QTableWidgetItem;
    for (int i = 0; i < n; i++)
    {
        for (int j  = 0; j < n; j++)
        {
            outputTable->setItem(i,j, new QTableWidgetItem(QString::number(mtrx->outputmatr_qt(i, j))));
        }
    }
    first->addWidget(outputTable);
    delete temp;
}
