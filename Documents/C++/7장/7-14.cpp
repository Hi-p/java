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
    void show(); // 멤버 함수 정의
    power& operator << (int n); // 멤버 함수로 연산자 오버로딩
};

void power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

power& power::operator << (int n) {
    kick += n;
    punch += n;
    return *this; // 현재 객체의 참조 반환
}

int main() {
    power a(1, 2); // 객체 생성
    a << 3 << 5 << 6; // 연산자 오버로딩을 사용하여 a 객체의 kick과 punch에 각각 3, 5, 6을 더함
    a.show(); // a의 상태 출력 (kick과 punch가 각각 3, 5, 6이 더해진 값)
}