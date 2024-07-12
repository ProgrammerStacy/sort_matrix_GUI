#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("Сортировка матрицы");
    wgt = new QWidget();
    setCentralWidget(wgt);
    first = new QVBoxLayout(wgt);
    firstTop = new QHBoxLayout();
    firstDown = new QHBoxLayout();
    left = new QVBoxLayout;
    inputSize = new QLineEdit;
    bSize = new QPushButton;
    welcomeText = new QLabel;

    first->addLayout(firstTop);
    first->addLayout(firstDown);
    firstDown->addLayout(left);
    welcomeText->setText("Введите размер квадратной таблицы:");
    first->insertWidget(0, welcomeText);
    bSize->setText("Ок");
    firstTop->addWidget(inputSize);
    firstTop->addWidget(bSize);

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
    n = inputSize->text().toInt();
    if (n % 2 != 0)
    {
        QMessageBox wrongValue;
        wrongValue.setText("Таблица должна быть квадратная. Введите четное число!");
        wrongValue.setIcon(QMessageBox::Critical);
        wrongValue.exec();
        return;
    }
    nextText->setText("Заполните таблицу целыми неповторяющимися числами: ");
    first->insertWidget(2, nextText);
    inputTable = new QTableWidget(n, n);
    left->addWidget(inputTable);
    leftBottom = new QHBoxLayout;
    left->addLayout(leftBottom);
    bNum = new QPushButton;
    bNum->setText("Ок");
    leftBottom->addWidget(bNum);
    mtrx = new Matrix(n);

    connect(bNum, SIGNAL(clicked()), this, SLOT(bNum_clicked()));
    bSize->setEnabled(false);
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
    bNum->setEnabled(false);
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
    firstDown->addWidget(outputTable);
    delete temp;
    delete mtrx;
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
