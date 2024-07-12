#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Matrix.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fill_outputTable();
    bool stringIsNum(QString) const;

private:
    int n;
    Ui::MainWindow *ui;
    QWidget* wgt;
    QVBoxLayout* first;
    QVBoxLayout* left;
    QVBoxLayout* right;
    QHBoxLayout* firstTop;
    QHBoxLayout* firstDown;
    QHBoxLayout* leftBottom;
    QLabel* welcomeText;
    QLabel* nextText;
    QLabel* image;
    QLineEdit* inputSize;
    QPushButton* bSize;
    QPushButton* bNum;
    QTableWidget* inputTable;
    QTableWidget* outputTable;
    Matrix* mtrx;
public slots:
    void bSize_clicked();
    void bNum_clicked();


};
#endif // MAINWINDOW_H
