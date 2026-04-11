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
    friend power operator+ (power op1, power op2); 
};

void power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

power operator+ (power op1, power op2) { 
    power tmp; // 새로운 power 임시 객체 생성
    tmp.kick = op1.kick + op2.kick;
    tmp.punch = op1.punch + op2.punch; // punch는 op2의 값을 그대로 사용
    return tmp; // 새로운 power 객체 반환
}

int main() {
    power a(3, 5), b(4, 6), c; // 객체 생성
    c = a + b; // operator+ 함수를 사용하여 a와 b 객체를 더한 결과를 c에 저장
    a.show(); // a의 상태 출력 (변경 없음)
    b.show(); // b의 상태 출력 (변경 없음)
    c.show(); // c의 상태 출력 (kick과 punch가 각각 더해진 값)
}