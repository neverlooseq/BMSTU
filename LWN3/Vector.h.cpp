#include <iostream>
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    int* data;   // указатель на динамический массив
    int size;    // размерность вектора

public:
    Vector();
    Vector(const int* arr, int n);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();
    int& operator[](int index);
    const int& operator[](int index) const;
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    bool operator<(const int* other) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend std::istream& operator>>(std::istream& is, Vector& v);
    int getSize() const { return size; }
};

#endif
