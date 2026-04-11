#include <iostream>
using namespace std;

class circle {
    int radius; // 멤버 변수 선언
public:
    circle(const circle& c); // 복사 생성자 선언
    circle() { radius = 1; } // 기본 생성자 정의 및 구현, 자동 인라인 함수
    circle(int radius) { this->radius = radius; } // 매개변수 있는 생성자 정의 및 구현, 자동 인라인 함수
    double getarea() { return 3.14 * radius * radius; } // 멤버 함수 정의 및 구현, 자동 인라인 함수
};

circle::circle(const circle& c) {
    this->radius = c.radius; // 복사 생성자 구현, radius 멤버 변수 복사
    cout << "복사 생성자 실행 radius = " << radius << endl; // 복사 생성자 실행 시 radius 값 출력
}

int main() {
    circle src(30); // circle 객체 src 생성, 매개변수 있는 생성자 호출
    circle dest(src); // circle 객체 dest 생성, 복사 생성자 호출하여 src 객체로 초기화

    cout << "원본의 면적 = " << src.getarea() << endl; // src 객체의 getarea() 함수 호출하여 면적 출력
    cout << "복사본의 면적 = " << dest.getarea() << endl; // dest 객체의 getarea() 함수 호출하여 면적 출력
}