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
    power operator+ (int op2); // 연산자 오버로딩 멤버 함수로 선언, 멤버 함수로 선언
};

void power::show() { // 멤버 함수 구현
    cout << "kick = " << kick << "," << " punch = " << punch << endl; 
}

power power::operator+ (int op2) {
    power tmp; // 임시 객체 생성
    tmp.kick = kick + op2; // kick 멤버에 op2를 더함
    tmp.punch = punch + op2; // punch 멤버에 op2를 더함
    return tmp; // 임시 객체 반환
}

int main() {
    power a(3, 5), b; // power 클래스의 객체 a, b 생성
    a.show(); // a 객체의 멤버 함수 show() 호출
    b.show(); // b 객체의 멤버 함수 show() 호출
    b = a + 2;
    a.show(); // a 객체의 멤버 함수 show() 호출
    b.show(); // b 객체의 멤버 함수 show() 호출
}