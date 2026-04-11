#include <iostream>
using namespace std;

class circle {
    int radius; // 접근 지정장 private, 멤버 변수 선언
public:
    circle() { radius = 1; } // 기본 생성자, 자동 인라인 함수
    circle(int r) { radius = r; } // 매개변수 있는 생성자, 자동 인라인 함수
    double getarea(); // 멤버 함수 선언
};

double circle::getarea() {
    return 3.14 * radius * radius;
}

int main() {
    circle donut; // circle 클래스의 객체 donut 생성, 기본 생성자 호출, 지역 변수
    circle pizza(30); // circle 클래스의 객체 pizza 생성, 매개변수 있는 생성자 호출, 지역 변수

    cout << donut.getarea() << endl; // donut 객체의 getarea() 멤버 함수 호출

    circle *p; // circle 클래스의 포인터 p 선언
    p = &donut; // 포인터 p에 donut 객체의 주소 저장
    cout << p -> getarea() << endl; // 포인터 p를 통해 donut 객체의 getarea() 멤버 함수 호출
    cout << (*p).getarea() << endl; // 포인터 p를 역참조하여 donut 객체의 getarea() 멤버 함수 호출

    p = &pizza; // 포인터 p에 pizza 객체의 주소 저장
    cout << p -> getarea() << endl; // 포인터 p를 통해 pizza 객체의 getarea() 멤버 함수 호출
    cout << (*p).getarea() << endl; // 포인터 p를 역참조하여 pizza 객체의 getarea() 멤버 함수 호출
}

