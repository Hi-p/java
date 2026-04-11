#include <iostream>
using namespace std;

class circle {
public:
    int radius; // 멤버 변수 선언
    circle(); // 생성자 선언
    circle(int r); // 매개변수가 있는 생성자 선언
    ~circle(); // 소멸자 선언
};

circle::circle() { // 생성자 정의
    radius = 1; // 생성자에서 멤버 변수 초기화
    cout << "반지름 " << radius << "인 원 생성" << endl;
}

circle::circle(int r) { // 매개변수가 있는 생성자 정의
    radius = r;
    cout << "반지름 " << radius << "인 원 생성" << endl;
}

circle::~circle() { // 소멸자 정의
    cout << "반지름 " << radius << "인 원 소멸" << endl;
}

int main() {
    circle donut; // 기본 생성자 호출, 지역 객체
    circle pizza(30); // 매개변수가 있는 생성자 호출, 지역 객체

    return 0;
}