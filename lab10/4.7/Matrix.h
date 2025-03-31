#pragma once
#include "../4.1/MyVector.h"
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    static size_t s_MatrixCount;
    std::string m_Name;
    MyVector<MyVector<T>> m_Data;

public:
    Matrix(size_t rows = 0, size_t cols = 0, const T& value = T());
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    ~Matrix();
    
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other);
    
    MyVector<T>& operator[](size_t row);
    const MyVector<T>& operator[](size_t row) const;
    
    void Resize(size_t newRows, size_t newCols, const T& value = T());
    
    void Print() const;
    
    size_t Rows() const { return m_Data.Size(); }
    size_t Cols() const { return (Rows() > 0) ? m_Data[0].Size() : 0; }
    const std::string& GetName() const { return m_Name; }

private:
    static std::string GenerateName();
    void Initialize(size_t rows, size_t cols, const T& value);
};

template <typename T>
size_t Matrix<T>::s_MatrixCount = 0;

template <typename T>
std::string Matrix<T>::GenerateName() {
    return "Matrix " + std::to_string(++s_MatrixCount);
}

template <typename T>
void Matrix<T>::Initialize(size_t rows, size_t cols, const T& value) {
    m_Data.Resize(rows);
    for (size_t i = 0; i < rows; ++i) {
        m_Data[i] = MyVector<T>(cols, value);
    }
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, const T& value) 
    : m_Name(GenerateName()) {
    Initialize(rows, cols, value);
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other)
    : m_Name(other.m_Name), m_Data(other.m_Data) {}

template <typename T>
Matrix<T>::Matrix(Matrix&& other)
    : m_Name(std::move(other.m_Name)), m_Data(std::move(other.m_Data)) {
    other.m_Name = "";
}

template <typename T> Matrix<T>::~Matrix() {
    s_MatrixCount--;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        m_Name = other.m_Name;
        m_Data = other.m_Data;
    }
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) {
    if (this != &other) {
        m_Name = std::move(other.m_Name);
        m_Data = std::move(other.m_Data);
        other.m_Name = "";
    }
    return *this;
}

template <typename T>
MyVector<T>& Matrix<T>::operator[](size_t row) {
    if (row >= Rows()) {
        throw std::out_of_range("Row index out of range: " + std::to_string(row));
    }
    return m_Data[row];
}

template <typename T>
const MyVector<T>& Matrix<T>::operator[](size_t row) const {
    if (row >= Rows()) {
        throw std::out_of_range("Row index out of range: " + std::to_string(row));
    }
    return m_Data[row];
}

template <typename T>
void Matrix<T>::Resize(size_t newRows, size_t newCols, const T& value) {
    size_t oldRows = Rows();
    m_Data.Resize(newRows);
    
    for (size_t i = 0; i < std::min(oldRows, newRows); ++i) {
        m_Data[i].Resize(newCols, value);
    }
    
    for (size_t i = oldRows; i < newRows; ++i) {
        m_Data[i] = MyVector<T>(newCols, value);
    }
}

template <typename T>
void Matrix<T>::Print() const {
    std::cout << m_Name << " (" << Rows() << "x" << Cols() << "):\n";
    for (size_t i = 0; i < Rows(); ++i) {
        for (size_t j = 0; j < Cols(); ++j) {
            std::cout << m_Data[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}