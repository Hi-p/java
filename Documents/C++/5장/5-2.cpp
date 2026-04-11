#include <iostream>
using namespace std;

class circle {
    int radius; // 멤버 변수 선언
public:
    circle() { radius = 1; } // 기본 생성자 정의 및 구현, 자동 인라인 함수
    circle(int radius) { this->radius = radius; } // 매개변수 있는 생성자 정의 및 구현, 자동 인라인 함수
    void setradius(int radius) { this->radius = radius; } // 멤버 함수 정의 및 구현, 자동 인라인 함수
    double getarea() { return 3.14 * radius * radius; } // 멤버 함수 정의 및 구현, 자동 인라인 함수
};

circle getcircle() { // circle 객체를 반환하는 함수 정의 및 구현
    circle tmp(30); // 지역 객체 tmp 생성
    return tmp; // tmp 객체 반환
}

int main() {
    circle c; // circle 객체 c 생성, 기본 생성자 호출
    cout << c.getarea() << endl; // c 객체의 getarea() 함수 호출하여 면적 출력

    c = getcircle(); // getcircle() 함수 호출하여 반환된 circle 객체로 c 객체 초기화
    cout << c.getarea() << endl; // c 객체의 getarea() 함수 호출하여 면적 출력
}