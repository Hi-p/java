#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x, int y) { this->x = x; this->y = y; }
    friend istream& operator >> (istream& ins, Point& a);
    friend ostream& operator << (ostream& stream, Point a);
};

istream& operator >> (istream& ins, Point& a) {
    cout << "x 좌표 >> ";
    ins >> a.x;
    cout << "y 좌표 >> ";
    ins >> a.y;
    return ins;
}

ostream& operator << (ostream& stream, Point a) {
    stream << "(" << a.x << ", " << a.y << ")";
    return stream;
}

int main() {
    Point p(0, 0);
    cin >> p;
    cout << p << endl;
}