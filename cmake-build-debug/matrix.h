#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>;

using namespace std;

class matrix
{
private:

    int m, n;
    double** p; // указатель на 2-мерный массив public:

public:

    matrix(); // конструктор по умолчанию
    matrix(int m, int n); // конструктор с параметрами matrix(const matrix& m); // конструктор копирования ~matrix(); // деструктор
    matrix(const matrix& other); // конструктор копирования
    ~Matrix(); // деструктор

 ///Оператор присваивания:
    matrix& operator=(const matrix& other);


 ///Составные операторы присвания:
    matrix& operator+=(const matrix& other);
    matrix& operator-=(const matrix& other);

 ///Умножение на константу слева:



 ///Умножение на константу слева:



 ///Деление на константу:
    matrix& operator/=(double scalar);


 ///Cложение матриц
     friend matrix operator+(const matrix& mat1, const matrix& mat2);


 ///Вычитание матриц
     friend matrix operator-(const matrix& mat1, const matrix& mat2);


 ///Умножение матриц
    friend matrix operator*(const matrix& mat1, const matrix& mat2);


 ///Сравнение матриц на равенство и неравенство
    friend bool operator==(const Matrix& mat1, const Matrix& mat2);
    friend bool operator!=(const Matrix& mat1, const Matrix& mat2);

 ///Ввод и вывод матрицы в удобном для пользователя виде
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat); // вывод матрицы
    friend std::istream& operator>>(std::istream& is, Matrix& mat); // ввод матрицы
};

#endif
