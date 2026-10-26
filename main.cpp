#include "Vector.h"
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cerr << "Не удалось открыть input.txt" << endl;
        return 1;
    }
    if (!fout.is_open()) {
        cerr << "Не удалось открыть output.txt" << endl;
        return 1;
    }

    Vector v1, v2;
    fin >> v1;
    fin >> v2;

    fout << "Исходные векторы:" << endl;
    fout << "v1 = " << v1 << endl;
    fout << "v2 = " << v2 << endl;
    fout << endl;

    fout << "Работа operator[]:" << endl;
    fout << "v1[0] = " << v1[0] << endl;
    v1[0] = 999;
    fout << "После v1[0] = 999: v1 = " << v1 << endl;
    fout << endl;

    fout << "Конструктор копирования:" << endl;
    Vector vCopy(v2);
    fout << "vCopy (копия v2) = " << vCopy << endl;
    fout << endl;

    fout << "Конструктор перемещения:" << endl;
    Vector vMoved(move(vCopy));
    fout << "vMoved (перемещённый vCopy) = " << vMoved << endl;
    fout << "vCopy после перемещения = " << vCopy << endl;
    fout << endl;

    fout << "Присваивание с копированием:" << endl;
    Vector v3;
    v3 = v2;
    fout << "v3 = v2 (копия): v3 = " << v3 << endl;
    fout << endl;

    fout << "Присваивание с перемещением:" << endl;
    Vector v4;
    v4 = move(v3);
    fout << "v4 (перемещённый v3) = " << v4 << endl;
    fout << "v3 после перемещения = " << v3 << endl;
    fout << endl;

    fout << "Операция сравнения Vector < int*:" << endl;

    int m;
    fin >> m;
    int* arr = new int[m];
    for (int i = 0; i < m; ++i)
        fin >> arr[i];

    fout << "Массив arr[" << m << "]: (";
    for (int i = 0; i < m; ++i) {
        fout << arr[i];
        if (i < m - 1) fout << ", ";
    }
    fout << ")" << endl;

    int len = (m < v2.getSize()) ? m : v2.getSize();

    Vector v2trimmed(arr, len);
    fout << "v2 (обрезанный до длины " << len << ") = " << v2trimmed << endl;

    if (len == m && len == v2.getSize()) {
        bool result = v2 < arr;
        fout << "v2 < arr  =>  " << (result ? "true" : "false") << endl;
    } else {
        bool result = v2trimmed < arr;
        fout << "(длины не совпадают, сравнение по первым " << len << " элементам)" << endl;
        fout << "v2 < arr  =>  " << (result ? "true" : "false") << endl;
    }

    Vector vEq(arr, len);
    fout << "vEq = " << vEq << endl;
    fout << "vEq < arr => " << ((vEq < arr) ? "true" : "false") << " (равные элементы - ложь)" << endl;

    Vector vGreater(arr, len);
    if (len > 0) vGreater[0] = arr[0] + 100;
    fout << "vGreater = " << vGreater << endl;
    fout << "vGreater < arr => " << ((vGreater < arr) ? "true" : "false") << " (первый больше - ложь)" << endl;

    Vector vLess(arr, len);
    if (len > 0) vLess[0] = arr[0] - 100;
    fout << "vLess = " << vLess << endl;
    fout << "vLess < arr => " << ((vLess < arr) ? "true" : "false") << " (первый меньше - истина)" << endl;

    delete[] arr;

    fin.close();
    fout.close();

    cout << "Готово. Результаты в output.txt" << endl;
    return 0;
}