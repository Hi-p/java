#include <iostream>
using namespace std;

class point {
    int x, y;
public:
    point(); // 기본 생성자
    point(int a, int b); // 매개변수 있는 생성자
    void show() { // 멤버 함수
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

point::point() : point(0, 0) { } // 기본 생성자는 매개변수 있는 생성자를 호출하여 (0, 0)으로 초기화, 위임 생성자
point::point(int a, int b) : x(a), y(b) { } // 매개변수 있는 생성자, 타겟 생성자

int main() {
    point origin; // 기본 생성자 호출, (0, 0)으로 초기화
    point target(10, 20); // 매개변수 있는 생성자 호출, (10, 20)으로 초기화
    origin.show();
    target.show();
}