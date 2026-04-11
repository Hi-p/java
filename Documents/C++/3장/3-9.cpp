#include <iostream>
using namespace std;

// C++ 구조체 선언
struct circle {
private:
    int radius; // 멤버 변수
public: 
    circle(int r) {
        radius = r; 
    }
    double getarea(); // 멤버 함수 선언
};

double circle::getarea() { // 멤버 함수 정의
    return 3.14 * radius * radius; 
}

int main() {
    circle waffle(3); // circle 구조체의 객체 생성
    cout << "면적은 " << waffle.getarea() << endl; // 멤버 함수 호출
}