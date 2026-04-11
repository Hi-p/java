#include <iostream>
using namespace std;

class circle {
    int radius; // 멤버 변수
public:
    circle() { radius = 1; } // 기본 생성자 선언 및 구현, 자동 인라인 함수
    circle(int r) { radius = r; } // 매개변수 있는 생성자 선언 및 구현, 자동 인라인 함수
    void setRadius(int r) { radius = r; } // 멤버 함수 선언 및 구현, 자동 인라인 함수
    double getarea(); // 멤버 함수 선언
};

double circle::getarea() {
    return 3.14 * radius * radius; // 멤버 함수 구현
}

int main() {
    circle circlearry[3] = { circle(10), circle(20), circle() }; // circle 객체 배열 선언 및 초기화
    for (int i = 0; i < 3; i++) {
        cout << "Circle " << i << "의 면적은 " << circlearry[i].getarea() << endl;  // 각 circle 객체의 면적 출력
    }
}