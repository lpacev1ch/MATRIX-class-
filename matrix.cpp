#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;


/// Конструктор по умолчанию
Matrix::Matrix() : m(0), n(0), p(nullptr) {}

/// Конструктор с параметрами
Matrix::Matrix(int rows, int cols) : m(rows), n(cols) {
    if (m <= 0 || n <= 0) {
        throw invalid_argument("Invalid matrix dimensions");
    }
    p = new double*[m];
    for (int i = 0; i < m; ++i) {
        p[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            p[i][j] = 0.0;
        }
    }
}

/// Конструктор копирования
Matrix::Matrix(const Matrix& other) : m(other.m), n(other.n) {
    p = new double*[m];
    for (int i = 0; i < m; ++i) {
        p[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            p[i][j] = other.p[i][j];
        }
    }
}

/// Деструктор
Matrix::~Matrix() {
    if (p != nullptr) {
        for (int i = 0; i < m; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }
}

/// Оператор присваивания
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // Очищаем текущие ресурсы
        for (int i = 0; i < m; ++i) {
            delete[] p[i];
        }
        delete[] p;

        // Копируем новые данные
        m = other.m;
        n = other.n;
        p = new double*[m];
        for (int i = 0; i < m; ++i) {
            p[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                p[i][j] = other.p[i][j];
            }
        }
    }
    return *this;
}

/// Оператор +=
Matrix& Matrix::operator+=(const Matrix& other) {
    if (m != other.m || n != other.n) {
        throw invalid_argument("Matrix dimensions mismatch");
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] += other.p[i][j];
        }
    }
    return *this;
}

/// Оператор -=
Matrix& Matrix::operator-=(const Matrix& other) {
    if (m != other.m || n != other.n) {
        throw invalid_argument("Matrix dimensions mismatch");
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] -= other.p[i][j];
        }
    }
    return *this;
}

/// Оператор умножения на константу слева
Matrix& Matrix::operator*=(double scalar) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] *= scalar;
        }
    }
    return *this;
}

/// Оператор деления на константу
Matrix& Matrix::operator/=(double scalar) {
    if (scalar == 0) {
        throw invalid_argument("Division by zero");
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][j] /= scalar;
        }
    }
    return *this;
}

/// Умножение на константу справа
Matrix operator*(const Matrix& mat, double scalar) {
    Matrix result(mat);
    result *= scalar;
    return result;
}

/// Умножение на константу слева
Matrix operator*(double scalar, const Matrix& mat) {
    return mat * scalar;
}

/// Сложение матриц
Matrix operator+(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n) {
        throw invalid_argument("Matrix dimensions mismatch");
    }
    Matrix result(mat1);
    result += mat2;
    return result;
