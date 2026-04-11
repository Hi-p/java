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
    friend power operator+ (int op1, power op2); // friend 함수로 int와 power 객체의 덧셈 연산자 오버로딩, friend 함수 선언
};

void power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

power operator+ (int op1, power op2) { 
    power tmp; // 새로운 power 임시 객체 생성
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch; // punch는 op2의 값을 그대로 사용
    return tmp; // 새로운 power 객체 반환
}

int main() {
    power a(3, 5), b; // 객체 생성
    a.show(); // a의 현재 상태 출력
    b.show(); // b의 현재 상태 출력
    b = 2 + a; // operator+ 함수를 사용하여 2와 a 객체를 더한 결과를 b에 저장
    a.show(); // a의 상태 출력 (변경 없음)
    b.show(); // b의 상태 출력 (kick이 2 증가, punch는 그대로)
}