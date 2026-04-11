#include <iostream>
using namespace std;

class power {
    int kick;
    int punch;
public: 
    power(int kick=0, int punch=0) { // 생성자 정의, 디폴트 매개변수 사용, 자동 인라인 함수
        this->kick = kick;
        this->punch = punch;
    }
    void show(); // 멤버 함수 선언
    power& operator+= (power op2); // 연산자 함수 멤버 함수로 선언
};

void power::show() { // 멤버 함수 구현
    cout << "kick = " << kick << "," << " punch = " << punch << endl; 
}

power& power::operator+= (power op2) {
    kick = kick + op2.kick; // kick 멤버에 op2의 kick 멤버를 더함
    punch = punch + op2.punch; // punch 멤버에 op2의 punch 멤버를 더함
    return *this; // 현재 객체의 참조 반환
}

int main() {
    power a(3, 5), b(4, 6), c; // power 클래스의 객체 a, b, c 생성
    a.show(); // a 객체의 멤버 함수 show() 호출
    b.show(); // b 객체의 멤버 함수 show() 호출
    c = a += b; // a 객체에 b 객체를 더한 후, 그 결과를 c 객체에 대입
    a.show(); // a 객체의 멤버 함수 show() 호출
    c.show(); // c 객체의 멤버 함수 show() 호출
}