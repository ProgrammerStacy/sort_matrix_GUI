#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wgt = new QWidget();
    setCentralWidget(wgt);
    first = new QHBoxLayout(wgt);
    left = new QVBoxLayout;
    leftTop = new QHBoxLayout;
    first->addLayout(left);

    welcomeText = new QLabel;
    welcomeText->setText("Введите размер таблицы:");
    left->addWidget(welcomeText);

    inputSize = new QLineEdit;
    bSize = new QPushButton;
    bSize->setText("Ок");

    left->addLayout(leftTop);
    leftTop->addWidget(inputSize);
    leftTop->addWidget(bSize);

    wgt->show();

    connect(bSize, SIGNAL(clicked()), this, SLOT(bSize_clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::bSize_clicked()
{
    nextText = new QLabel;
    nextText->setText("Заполните таблицу целыми неповторяющимися числами: ");
    left->addWidget(nextText);
    n = inputSize->text().toInt();
    inputTable = new QTableWidget(n, n);
    left->addWidget(inputTable);

    leftBottom = new QHBoxLayout;
    left->addLayout(leftBottom);

    bNum = new QPushButton;
    bNum->setText("Ок");
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
                s = temp->text();
                if (stringIsNum(s))
                {
                mtrx->inputmatr_qt(i, j, s.toInt());
                }
                else
                {
                    QMessageBox wrongValue;
                    wrongValue.setText("Таблица должна быть заполнена только целыми числами!");
                    wrongValue.setIcon(QMessageBox::Critical);
                    wrongValue.exec();
                    delete temp;
                    return;
                }
            }
            else
            {
                QMessageBox wrongValue;
                wrongValue.setText("Все ячейки таблицы должны быть заполнены!");
                wrongValue.setIcon(QMessageBox::Critical);
                wrongValue.exec();
                delete temp;
                return;
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
bool MainWindow::stringIsNum(QString s) const
{
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (!s[i].isDigit()) return false;
    }
    return true;
}
