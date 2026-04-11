#include <iostream>
using namespace std;

class circle {
public:
    int radius; // 멤버 변수
    double getarea(); // 멤버 함수의 선언
}; // 선언부

double circle::getarea() { // 멤버 함수의 정의
    return 3.14 * radius * radius;
}

int main() {
    circle dount; // 객체 생성
    dount.radius = 1; // dount 객체의 radius 멤버 변수 값을 1로 설정
    double area = dount.getarea(); // dount 객체의 getarea() 멤버 함수 호출
    cout << "dount의 면적은 " << area << endl; // 결과 출력

    circle pizza; // 객체 생성
    pizza.radius = 30; // pizza 객체의 radius 멤버 변수 값을 30로 설정
    area = pizza.getarea(); // pizza 객체의 getarea() 멤버 함수 호출
    cout << "pizza의 면적은 " << area << endl; // 결과 출력
}