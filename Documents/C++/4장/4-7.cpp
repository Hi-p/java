#include <iostream>
using namespace std;

class circle {
    int radius; // private 멤버 변수 radius 선언
public:
    circle(); // 기본 생성자 선언
    circle(int r); // 매개변수 있는 생성자 선언
    ~circle(); // 소멸자 선언
    void setRadius(int r) { radius = r; } // 멤버 함수 선언 및 구현, 자동 인라인 함수
    double getarea() { return 3.14 * radius * radius; }; // 멤버 함수 선언 및 구현
};

circle::circle() {
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl; // 기본 생성자 실행 시 메시지 출력
}

circle::circle(int r) {
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl; // 매개변수 있는 생성자 실행 시 메시지 출력
}

circle::~circle() {
    cout << "소멸자 실행 radius = " << radius << endl; // 소멸자 실행 시 메시지 출력
}

int main() {
    int radius; // 지역 변수 radius 선언
    while(true) {
        cout << "정수 반지름 입력(음수이면 종료): ";
        cin >> radius; // 사용자로부터 반지름 입력 받기
        if (radius < 0)
            break; // 입력된 반지름이 음수이면 반복문 종료
        circle *p = new circle(radius); // 동적 할당으로 circle 객체 생성
        cout << "원의 면적은 " << p -> getarea() << endl; // circle 객체의 getarea() 함수 호출하여 면적 출력
        delete p; // 동적 할당된 circle 객체 반환
    }
}