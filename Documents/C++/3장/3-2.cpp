#include <iostream>
using namespace std;

class Rectangle {
public:
    int width; // 멤버 변수
    int height; // 멤버 변수
    int getarea(); // 멤버 함수의 선언
}; // 선언부

int Rectangle::getarea() { // 멤버 함수의 정의
    return width * height;
}

int main() {
    Rectangle rect; // 객체 생성
    rect.width = 3; // rect 객체의 width 멤버 변수 값을 3으로 설정
    rect.height = 5; // rect 객체의 height 멤버 변수 값을 5로 설정
    cout << "사각형의 면적은 " << rect.getarea() << endl; // 결과 출력
}