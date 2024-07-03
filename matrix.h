#ifndef MATRIX_H
#define MATRIX_H

#pragma once

#include <iostream>
using namespace std;
typedef int telem;
typedef telem* tstr;
typedef tstr* tmatr;


class Matrix
{
public:
    Matrix();
    Matrix(int);
    ~Matrix();
    void inputmatr();
    void inputmatr_qt(int, int, int);
    int outputmatr_qt(int, int);
    void outputmatr();
    void sort_vibor(tstr a, int n);
    void sort_matr();
    void obnulenie();

private:
    int str;
    tmatr a;

};

#endif
