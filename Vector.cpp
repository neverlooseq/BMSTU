#include "Vector.h"
#include <cstring>

// Конструктор без параметров
Vector::Vector() : data(nullptr), size(0) {}

// Конструктор из массива
Vector::Vector(const int* arr, int n) : data(nullptr), size(0) {
    if (n > 0 && arr != nullptr) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }
}

// Конструктор копирования
Vector::Vector(const Vector& other) : data(nullptr), size(0) {
    std::cout << "[Конструктор копирования] size = " << other.size << std::endl;
    size = other.size;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
}

// Конструктор перемещения
Vector::Vector(Vector&& other) noexcept : data(nullptr), size(0) {
    std::cout << "[Конструктор перемещения] size = " << other.size << std::endl;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

Vector::~Vector() {
    delete[] data;
}

int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Ошибка: индекс " << index << " вне диапазона [0, " << size - 1 << "]\n";
        static int dummy = 0;
        return dummy;
    }
    return data[index];
}

const int& Vector::operator[](int index) const {
    if (index < 0 || index >= size) {
        std::cerr << "Ошибка: индекс " << index << " вне диапазона [0, " << size - 1 << "]\n";
        static int dummy = 0;
        return dummy;
    }
    return data[index];
}

Vector& Vector::operator=(const Vector& other) {
    std::cout << "[Присваивание с копированием] size = " << other.size << std::endl;
    if (this == &other)
        return *this;

    delete[] data;
    data = nullptr;
    size = other.size;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    std::cout << "[Присваивание с перемещением] size = " << other.size << std::endl;
    if (this == &other)
        return *this;

    delete[] data;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
    return *this;
}

bool Vector::operator<(const int* other) const {
    if (other == nullptr || size == 0)
        return false;

    for (int i = 0; i < size; ++i) {
        if (data[i] < other[i])
            return true;
        if (data[i] > other[i])
            return false;
    }
    return false; // все элементы равны
}

// Вывод в поток
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "Vector[" << v.size << "]: (";
    for (int i = 0; i < v.size; ++i) {
        os << v.data[i];
        if (i < v.size - 1) os << ", ";
    }
    os << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    int n;
    if (!(is >> n)) return is;

    delete[] v.data;
    v.data = nullptr;
    v.size = 0;

    if (n > 0) {
        v.size = n;
        v.data = new int[n];
        for (int i = 0; i < n; ++i)
            is >> v.data[i];
    }
    return is;
}