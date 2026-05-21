#include <iostream>
using namespace std;

class point {
    int x, y;
public:
    point(int x = 0, int y = 0) { this->x = x; this->y = y; } // 생성자, 자동 인라인 함수
    friend ostream& operator << (ostream& stream, point a);
};

ostream& operator << (ostream& stream, point a) {
    stream << "(" << a.x << ", " << a.y << ")";
    return stream; // 연산자 오버로딩 함수는 항상 참조형을 반환해야 한다. cout을 참조형으로 반환하여 연쇄적으로 사용할 수 있도록 한다.
}

int main() {
    point p(3, 4);
    cout << p << endl; // operator << 함수가 호출되어 (3, 4) 가 출력됩니다.

    point q(1, 100), r(2, 200);
    cout << q << r << endl; // operator << 함수가 연쇄적으로 호출되어 (1, 100)(2, 200) 이 출력됩니다.
}