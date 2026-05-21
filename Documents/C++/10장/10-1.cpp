#include <iostream>
using namespace std;

class circle {
    int radius;
public:
    circle(int radius = 1) { this->radius = radius; }
    int getradius() { return radius; }
};

template <class T>
void myswap(T &a, T &b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 4, b = 5;
    myswap(a, b);
    cout << "a = " << a << ", " << "b = " << b << endl;

    double c = 3.14, d = 2.71;
    myswap(c, d);
    cout << "c = " << c << ", " << "d = " << d << endl;

    circle donut(5), pizza(20);
    myswap(donut, pizza);
    cout << "donut 반지름 = " << donut.getradius() << ", " << "pizza 반지름 = " << pizza.getradius() << endl;
}