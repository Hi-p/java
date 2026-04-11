#include <iostream>
using namespace std;

class circle {
    int radius; // 접근 지정장 private, 멤버 변수 선언
public:
    circle() { radius = 1; } // 기본 생성자 선언 및 구현, 자동 인라인 함수
    circle(int r) { radius = r; } // 매개변수 있는 생성자 선언 및 구현, 자동 인라인 함수
    void setradius(int r) { radius = r; } // 멤버 함수 선언 및 구현, 자동 인라인 함수
    double getarea(); // 멤버 함수 선언
};

double circle::getarea() {
    return 3.14 * radius * radius;
}

int main() {
    circle circlearray[3]; // circle 클래스의 객체 배열 circlearray 생성, 기본 생성자 호출, 지역 변수

    circlearray[0].setradius(10); // circlearray 배열의 첫 번째 요소의 setradius() 멤버 함수 호출
    circlearray[1].setradius(20); // circlearray 배열의 두 번째 요소의 setradius() 멤버 함수 호출
    circlearray[2].setradius(30); // circlearray 배열의 세 번째 요소의 setradius() 멤버 함수 호출

    for (int i = 0; i < 3; i++) { // 배열의 각 원소 객체의 멤버 접근
        cout << "Circle " << i << "의 면적은 " << circlearray[i].getarea() << endl; // circlearray 배열의 각 요소의 getarea() 멤버 함수 호출
    }

    circle *p; // circle 클래스의 포인터 p 선언
    p = circlearray; // 포인터 p에 circlearray 배열의 첫 번째 요소의 주소 저장
    for(int i = 0; i < 3; i++) { // 객체 포인터로 배열 요소 접근
        cout << "Circle " << i << "의 면적은 " << p -> getarea() << endl; // 포인터 p를 통해 circlearray 배열의 각 요소의 getarea() 멤버 함수 호출
        p++; // 포인터 p를 다음 요소로 이동
    }
}