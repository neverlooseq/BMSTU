#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Square {
protected:
    int side;
public:
    Square() {
        side = 0;
    }

    Square(int a) {
        side = a;
    }

    virtual int getPerimetr() {
        return 4 * side;
    }

    virtual void print() {
        cout << "Side: " << side << endl;
        cout << "Perimetr: " << getPerimetr() << endl;
    }

    void print(int indent) {
        cout << string(indent, ' ');
        print();
    }

    virtual ~Square() {
    }
};

class Rectangle : public Square {
    int second_side;
public:
    using Square::print;   // ← ДОБАВЛЕНО

    Rectangle(int a, int b) {
        second_side = b;
        side = a;
    }

    int getPerimetr() override {
        return 2 * (second_side + side);
    }

    void print() override {
        cout <<"Side 1: " <<  side << ", Side 2: " << second_side << endl;
        cout << "Perimetr: " << getPerimetr() << endl;
    }
};

int main() {
    Square s(8);
    Rectangle r(4, 14);

    cout << "   Square" << endl;
    s.print();

    cout << "   Rectangle" << endl;
    r.print();

    cout << "   Static polymorphism" << endl;
    s.print();
    s.print(4);
    r.print();
    r.print(4);

    cout << "   Dynamic polymorphism" << endl;
    Square *p = &r;
    p->print();

    cout << "   Vector" << endl;
    vector<Square *> v;
    v.push_back(&s);
    v.push_back(&r);

    int sum = 0;
    for (Square *q: v) {
        q->print();
        sum += q->getPerimetr();
    }
    cout << "Sum perimetrs = " << sum << endl;
    return 0;
}
