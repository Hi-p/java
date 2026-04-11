#include <iostream>
using namespace std;

class circle {
    int radius; // 멤버 변수 선언
public:
    circle(); // 기본 생성자 선언
    circle(int r); // 매개변수가 있는 생성자 선언
    ~circle(); // 소멸자 선언
    double getarea() { return 3.14 * radius * radius; } // 원의 면적을 계산하는 멤버 함수 선언 및 구현, 자동 인라인 함수
    int getradius() { return radius; } // 원의 반지름을 반환하는 멤버 함수 선언 및 구현, 자동 인라인 함수
    void setradius(int radius) { this->radius = radius; } // 원의 반지름을 설정하는 멤버 함수 선언 및 구현, 자동 인라인 함수
};

circle::circle() {
    radius = 1; // 기본 생성자에서 반지름을 1로 초기화
    cout << "생성자 실행 radius = " << radius << endl; // 생성자 실행 시 반지름 값을 출력
}

circle::circle(int radius) { 
    this->radius = radius; // 매개변수가 있는 생성자에서 반지름을 설정
    cout << "생성자 실행 radius = " << radius << endl; // 생성자 실행 시 반지름 값을 출력
}

circle::~circle() {
    cout << "소멸자 실행 radius = " << radius << endl; // 소멸자 실행 시 반지름 값을 출력
}

void increase(circle c) {
    int r = c.getradius(); // 전달된 circle 객체의 반지름을 가져옴
    c.setradius(r + 1); // 전달된 circle 객체의 반지름을 1 증가시킴
}

int main() {
    circle waffle(30); // waffle 객체 생성, 반지름 30으로 초기화
    increase(waffle); // waffle 객체를 increase 함수에 전달하여 반지름을 증가시키려고 시도
    cout << waffle.getradius() << endl; // waffle 객체의 반지름을 출력, increase 함수에서 반지름이 증가되지 않았음을 확인
}