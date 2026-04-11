#include <iostream>
using namespace std;

class circle {
    int radius;
public:
    circle() { radius = 1; } // 기본 생성자 선언 및 구현, 자동 인라인 함수
    circle(int r) { radius = r; } // 매개변수 있는 생성자 선언 및 구현, 자동 인라인 함수
    void setRadius(int r) { radius = r; } // 멤버 함수 선언 및 구현, 자동 인라인 함수
    double getarea(); // 멤버 함수 선언
};

double circle::getarea() { // 멤버 함수 구현
    return 3.14 * radius * radius;
}

int main() {
    circle circles[2][3]; // 2행 3열의 circle 객체 배열 선언

    circles[0][0].setRadius(1); // 첫 번째 행의 첫 번째 열에 있는 circle 객체의 반지름을 1로 설정
    circles[0][1].setRadius(2); // 첫 번째 행의 두 번째 열에 있는 circle 객체의 반지름을 2로 설정
    circles[0][2].setRadius(3); // 첫 번째 행의 세 번째 열에 있는 circle 객체의 반지름을 3로 설정
    circles[1][0].setRadius(4); // 두 번째 행의 첫 번째 열에 있는 circle 객체의 반지름을 4로 설정
    circles[1][1].setRadius(5); // 두 번째 행의 두 번째 열에 있는 circle 객체의 반지름을 5로 설정
    circles[1][2].setRadius(6); // 두 번째 행의 세 번째 열에 있는 circle 객체의 반지름을 6로 설정

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Circle [" << i << "," << j << "]의 면적은 " << circles[i][j].getarea() << endl; // 각 circle 객체의 면적 출력
        }
    }
}