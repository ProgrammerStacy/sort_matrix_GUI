#include <QString>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QPixmap>
#include "./ui_mainwindow.h"
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("Сортировка матрицы");
    wgt = new QWidget();
    // создание всех layout для размещения виджетов и правильной иерархии для объектов,
    // чтобы при вызове деструктора центрального виджета, так же удалились и его наследники
    setCentralWidget(wgt);
    first = new QVBoxLayout(wgt);
    firstTop = new QHBoxLayout();
    firstDown = new QHBoxLayout();
    left = new QVBoxLayout;
    right = new QVBoxLayout;
    leftBottom = new QHBoxLayout;
    inputSize = new QLineEdit;
    bSize = new QPushButton;
    welcomeText = new QLabel;
    nextText = new QLabel;
    first->addLayout(firstTop);
    first->addLayout(firstDown);
    firstDown->addLayout(left);
    firstDown->addLayout(right);
    // установка приветствия пользователя и инструкции к действиям
    welcomeText->setText("Введите размер квадратной матрицы:");
    nextText->setText("совет: для лучшей демонстрации вводите размер от 4");
    first->insertWidget(0, welcomeText);
    first->insertWidget(2, nextText);
    bSize->setText("Ок");
    firstTop->addWidget(inputSize);
    firstTop->addWidget(bSize);
    // демонстрация главного  виджета
    wgt->show();
    // связь кнопки ок для передачи размеров будущей таблицы, введенный пользователем
    connect(bSize, SIGNAL(clicked()), this, SLOT(bSize_clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::bSize_clicked()
{
    QString s;

    s = inputSize->text();
    // проверка на корректность вводимого пользователем значения
    if (!stringIsNum(s))
    {
        QMessageBox wrongValue;
        wrongValue.setText("Введите число!");
        wrongValue.setIcon(QMessageBox::Critical);
        wrongValue.exec();
        return;
    }
    n = s.toInt(); // int n является приватным полем класса MainWindow, чтобы к нему был доступ из разных функций этого класса
    // проверка на четность вводимого числа
    if (n % 2 != 0)
    {
        QMessageBox wrongValue;
        wrongValue.setText("Таблица должна быть квадратная. Введите четное число!");
        wrongValue.setIcon(QMessageBox::Critical);
        wrongValue.exec();
        return;
    }
    // если пользователь ввел корректный размер матрицы, то на экране отобразится таблица для заполнения
    nextText->setText("Заполните таблицу целыми числами: ");
    inputTable = new QTableWidget(n, n);
    bNum = new QPushButton;
    bNum->setText("Ок");
    // установка виджетов в нужные положения
    left->addWidget(inputTable);
    left->addLayout(leftBottom);
    leftBottom->addWidget(bNum);

    // связь кнопки и сигнала для считывания данных, который ввел пользователь
    connect(bNum, SIGNAL(clicked()), this, SLOT(bNum_clicked()));
    // отключение кнопки, так как предполагается разовое использование программы
    bSize->setEnabled(false);
}
void MainWindow::bNum_clicked()
{
    QTableWidgetItem* temp = new QTableWidgetItem;
    QString s;
    // для таблицы создается объектр класса Matrix в котором и будет происходить сортировка значений таблицы
    mtrx = new Matrix(n);
    // заполнение объекта класса Matrix и проверка корректности вводимых значений
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
    // в случае успешного заполнения таблицы, значения переданные в mtrx сортируются и передаются в таблицу вывода
    mtrx->sort_matr();
    mtrx->obnulenie();
    fill_outputTable();
}
void MainWindow::fill_outputTable()
{
    // заполнение таблицы вывода
    outputTable = new QTableWidget(n, n);
    QTableWidgetItem* temp = new QTableWidgetItem;
    for (int i = 0; i < n; i++)
    {
        for (int j  = 0; j < n; j++)
        {
            outputTable->setItem(i,j, new QTableWidgetItem(QString::number(mtrx->outputmatr_qt(i, j))));
        }
    }
    right->addWidget(outputTable);
    QPixmap sortAreaP(":/p/SortArea");
    image = new QLabel;
    right->addWidget(image);
    image->setPixmap(sortAreaP);
    delete temp;
    delete mtrx;
}
// функция для проверки, является ли введенная строка числом
bool MainWindow::stringIsNum(QString s) const
{
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (!s[i].isDigit()) return false;
    }
    return true;
}
