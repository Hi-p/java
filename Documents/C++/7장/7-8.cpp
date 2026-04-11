#include <iostream>
using namespace std;

class power {
    int kick;
    int punch;
public:
    power(int kick=0, int punch=0) { // 생성자 정의
        this->kick = kick;
        this->punch = punch;
    }
    void show(); // 멤버 함수 선언
    power& operator++ (); // 전위 증가 연산자 선언
};

void power::show() { // 멤버 함수 구현
    cout << "kick = " << kick << "," << " punch = " << punch << endl;
}

power& power::operator++ () {
    kick++;
    punch++;
    return *this; // 현재 객체의 참조 반환
}

int main() {
    power a(3, 5), b; // 객체 생성
    a.show(); // a 객체의 상태 출력
    b.show(); // b 객체의 상태 출력
    b = ++a; // a 객체를 전위 증가시키고 b에 대입
    a.show(); // a 객체의 상태 출력
    b.show(); // b 객체의 상태 출력
}