#include <iostream>
using namespace std;

class circle {
public:
    int radius; // 멤버 변수
    circle(); // 매개변수 없는 생성자 선언
    circle(int r); // 매개변수 있는 생성자 선언
    double getarea(); // 원의 넓이를 계산하는 멤버 함수 선언
};

circle::circle() { // 매개변수 없는 생성자 정의
    radius = 1; // 기본 반지름 값 설정
    cout << "반지름 " << radius << "인 원 생성" << endl;
}

circle::circle(int r) { // 매개변수 있는 생성자 정의
    radius = r; // 전달된 반지름 값 설정
    cout << "반지름 " << radius << "인 원 생성" << endl;
}

double circle::getarea() {
    return 3.14 * radius * radius; // 원의 넓이 계산
}

int main() {
    circle dount; // 객체 생성과 동시에 매개변수 없는 생성자 호출
    double area = dount.getarea(); // 원의 넓이 계산
    cout << "dount 면적은 " << area << endl; // 원의 넓이 출력

    circle pizza(30); // 객체 생성과 동시에 매개변수 있는 생성자 호출
    area = pizza.getarea(); // 원의 넓이 계산
    cout << "pizza 면적은 " << area << endl; // 원의 넓이 출력
}