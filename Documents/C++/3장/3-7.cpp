#include <iostream>
using namespace std;

class circle {
public:
    int radius; // 멤버 변수
    circle(); // 생성자 선언
    circle(int r); // 매개변수가 있는 생성자 선언
    ~circle(); // 소멸자 선언
};

circle::circle() { // 기본 생성자 정의
    radius = 1; // 기본 생성자에서 반지름을 1로 초기화
    cout << "반지름 " << radius << "원 생성" << endl;
}

circle::circle(int r) { // 매개변수가 있는 생성자 정의
    radius = r; // 매개변수로 받은 값을 반지름으로 초기화
    cout << "반지름 " << radius << "원 생성" << endl;
}

circle::~circle() {
    cout << "반지름 " << radius << "원 소멸" << endl;
}

circle globalDonut(1000); // 전역 객체 선언
circle globalPizza(2000); // 전역 객체 선언

void f() {
    circle fDonut(100); // 지역 객체 선언
    circle fPizza(200); // 지역 객체 선언 
}

int main() {
    circle mainDonut; // 지역 객체 선언
    circle mainPizza(30); // 지역 객체 선언
    f(); // 함수 호출하여 지역 객체 생성 및 소멸
}