
#ifndef MATRIX_H
#define MATRIX_H

#pragma once

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
    int outputmatr_qt(int, int) const;
    void outputmatr() const;
    void sort_vibor(tstr, int);
    void sort_matr();
    void obnulenie();

private:
    int str;
    tmatr a;

};

#endif
