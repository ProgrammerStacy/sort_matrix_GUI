#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Matrix.h"
#include <QWidget>
#include <QLineEdit>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
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

private:
    int n;
    Ui::MainWindow *ui;
    QWidget* wgt;
    QHBoxLayout* first;
    QVBoxLayout* left;
    QHBoxLayout* leftTop;
    QHBoxLayout* leftBottom;
    QLabel* welcomeText;
    QLabel* nextText;
    QLabel* warningText;
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
