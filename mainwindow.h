#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include "Matrix.h"
#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QMessageBox>



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
    QHBoxLayout* firstTop;
    QHBoxLayout* firstDown;
    QHBoxLayout* leftBottom;
    QLabel* welcomeText;
    QLabel* nextText;
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
