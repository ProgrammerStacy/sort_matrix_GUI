#include "Matrix.h"

Matrix::Matrix() //конструктор без аргументов
{
    str = 10;
    a = new tstr[str]; //выделение динамической памяти под массив
    for (int i = 0; i < str; i++){	//Цикл выделения памяти под каждую строку.
        *(a + i) = new telem[str];
        for (int j = 0; j < str; j++)
        {
            *(*(a+i)+j )= 0;
        }
    }
}
Matrix::Matrix(int x) //конструктор с одним аргументом
{
    str = x;
    a = new tstr[str]; //выделение динамической памяти под массив
    for (int i = 0; i < str; i++){	//Цикл выделения памяти под каждую строку.
        *(a + i) = new telem[str];
        for (int j = 0; j < str; j++)
        {
            *(*(a+i)+j )= 0;
        }
    }
}
Matrix::~Matrix() //деструктор
{
    for (int i = 0; i < str; i++) delete a[i];
    delete a;
}
void Matrix::inputmatr()
{
    cout << " Enter the elements line by line separated by spaces" << endl;
    cout << " two-dimensional array of size " << str << "x" << str << endl;
    cout << " After entering the line, press <Enter>" << endl;
    for (int i = 0; i < str; i++){
        cout << " ";
        for (int j = 0; j < str; j++)
            cin >> *(*(a + i) + j);
    }
}
void Matrix::inputmatr_qt(int i, int j, int temp)
{
    *(*(a + i) + j) = temp;

}
int Matrix::outputmatr_qt(int i, int j)
{
    return *(*(a + i) + j);
}
//сортировка элементов массива по возрастанию методом выбора минимума
void Matrix::sort_vibor(tstr a, int n)
{
    int k, imin;
    telem z;
    for (int i = 0; i < str - 1; i++) {
        imin = i;		//поиск очередного минимума
        for (int k = i + 1; k < n; k++) if (a[k] < a[imin]) imin = k;
        //перестановка элементов
        z = a[i];
        a[i] = a[imin];
        a[imin] = z;
    }
}
void Matrix::sort_matr() //ограничение области сортировки происходит за счет
{                        //разделения матрицы на симметричные области
    int start = 0;
    for (int i = 0; i < str/2 ; i ++)
    {
        int j = i;
        int end = i + 1;
        int len = end - start;
        tstr temp1 = new telem [len];
        tstr temp2 = new telem [len];
        tstr temp3 = new telem [len];
        tstr temp4 = new telem [len];
        for (int x = 0; x <= j; x ++)
        {
            temp1[x] = a[i][x];
            temp2[x] = a[str-i-1][x];
            temp3[x] = a[i][str/2 + x];
            temp4[x] = a[str-i-1][str/2 + x];
        }
        if (i != 0 ){
            sort_vibor(temp1, len);
            sort_vibor(temp2, len);
            sort_vibor(temp3, len);
            sort_vibor(temp4, len);
        }
        for (int x = 0; x < str/2; x ++)
        {
            if (x <= j){
                a[i][x] = temp1[x];
                a[str-i-1][x] = temp2[x];
                a[i][str/2 + x] = temp3[x];
                a[str-i-1][str/2 + x] = temp4[x];}
        }
        delete temp1;
        delete temp2;
        delete temp3;
        delete temp4;
    }


}
void Matrix::obnulenie() // по условию, все что находится вне области сортировки
{                        // должно быть заменено на 0
    for (int j = 0; j < str/2 ; j ++)
    {
        for (int x = 0; x < str/2; x ++)
        {
            if (x > j){
                a[j][x] = 0;
                a[str-j-1][x] = 0;
                a[j][str/2 + x] = 0;
                a[str-j-1][str/2 + x] = 0;
            }
        }
    }
}
void Matrix::outputmatr()
{
    int i, j;
    for (i = 0; i < str; i++) {
        for (j = 0; j < str; j++) {
            cout.width(2); // ширина поля для выводимого параметра
            cout << *(*(a + i) + j) << ' ';
        }
        cout << '\n';
    }
}
