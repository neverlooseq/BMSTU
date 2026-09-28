#include <iostream>
#include <vector> // По заданию, для работы с динамическими массивами

using namespace std; // Не писать std

struct Item {
    // Задаём структуру предмет багажа по условию
    string nameItem;
    int weight;
};

struct Passeger {
    // Задаём структуру пассажир по условию
    string namePasseger;

    vector<Item> items;

    int count = 1;
};

int main() {
    system("chcp 65001 > nul"); // установить кодировку, чтобы кирилица выводилась в консоли (команду нашел в интернете)
    int n; //Количество пассажиров
    string weight20 = "нет";
    //Для задания 22 (можно через bool, но там при выводе результата выдает единицу, либо true/false, я хочу для единой картины весь вывод сделать на русском языке)
    cout << "Введи количество пассажиров: ";
    cin >> n;
    cin.ignore(); // Нужна для того, чтобы getline считался нормально, а не \n
    vector<Passeger> passegers(n); // Создания вектора типа Passeger размером n
    double chislo_pass_30 = 0, sumi = 0; // Переменная для 21 задания, суммарный вес всех предметов багажа
    for (int i = 0; i < n; i++) {
        string proverka; // объявление переменной нашей проверки на количество предметов в багаже
        cout << "Введите ФИО пассажира: " << endl;
        getline(cin, passegers[i].namePasseger); // ввод фио пассажира
        cout << "Введите количество предметов в багаже : " << endl;
        getline(cin, proverka);
        passegers[i].count = proverka != "" ? stoi(proverka) : 1;
        // проверка на количество предметов, если ентер, то предмет один будет, если нет, тогда строковый тип данных превратится в целочисленный
        passegers[i].items.resize(passegers[i].count); //изменяем размер вектора заданного первой структурой
        for (int j = 0; j < passegers[i].count; j++) {
            //ввод предметов багажа
            cout << "Введите название предмета багажа : " << endl;
            getline(cin, passegers[i].items[j].nameItem);
            cout << "Введите вес предмета багажа : " << endl;
            cin >> passegers[i].items[j].weight;
            cin.ignore();
        }
    }
    cout <<n << endl;
    for (int i = 0; i < n; i++) {
        //цикл направленный на решение 21,22 задачи и вычисления суммарного веса всех багажей
        cout <<passegers[i].namePasseger<<endl;
        cout << passegers[i].count<<endl;
        double sum = 0;
        for (int j = 0; j < passegers[i].count; j++) {
            cout << passegers[i].items[j].nameItem<<endl;
            cout << passegers[i].items[j].weight<<endl;
            sum += passegers[i].items[j].weight;
            weight20 = ((passegers[i].items[j].weight > 20) && (passegers[i].count == 1)) ? "да" : weight20;
        }
        chislo_pass_30 = sum > 30 ? chislo_pass_30 + 1 : chislo_pass_30;
        sumi += sum;
    }
    int bolAverage = 0, bolThree = 0, maxLuggage = 0; // 24 и 25 задание
    string maxName;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < passegers[i].count; j++) {
            sum += passegers[i].items[j].weight;
        }
        if (sum > maxLuggage) {
            maxLuggage = sum;
            maxName = passegers[i].namePasseger;
        }


        double avg = (passegers[i].count > 0) ? sum / passegers[i].count : 0.0;
        //Нахождение среднего веса одного предмета для одного пассажира с проверкой, что у пассажира есть багаж
        cout << "Средний вес одного предмета багажа для пассажира " << passegers[i].namePasseger << ": " << avg << endl;
        bolThree = (passegers[i].count) > 3 ? bolThree + 1 : bolThree;
        //Счетчик пассажиров, у которых предметов в багаже > 3
        bolAverage = sum > (sumi / n) ? bolAverage + 1 : bolAverage;
        //Счетчик пассажиров, у которых вес багажа превосходит средний
    }
    cout << "Число пассажиров, вес багажа которых превышает 30 кг: " << chislo_pass_30 << endl;
    cout << "Имеется ли пассажир, багаж которого состоит из одной вещи весом более чем в 20 кг: " << weight20 << endl;
    cout << "Средний вес багажа для пассажира: " << sumi / n << endl;
    cout << "Количество пассажиров, вес багажа которых превосходит средний: " << bolAverage << endl;
    cout << "Количество пассажиров, имеющих более трех вещей в багаже: " << bolThree << endl;
    cout << "Пассажир с максимальным весом багажа: " << maxName << endl;
    return 0;
}
