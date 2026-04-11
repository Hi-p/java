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
    friend power& operator++ (power& op); // 전위 증가 연산자 오버로딩
    friend power operator++ (power& op, int x); // 후위 증가 연산자 오버로딩
};

void power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

power& operator++ (power& op) { // 전위 증가 연산자 오버로딩
    op.kick++;
    op.punch++;
    return op; // 현재 객체의 참조 반환
}

power operator++ (power& op, int x) { // 후위 증가 연산자 오버로딩
    power tmp = op; // 현재 객체의 값을 복사
    op.kick++;
    op.punch++;
    return tmp; // 증가하기 전의 값 반환
}

int main() {
    power a(3, 5), b; // 객체 생성
    b = ++a; // 전위 증가 연산자 사용: a의 kick과 punch가 각각 1씩 증가한 후, b에 그 값이 저장
    a.show(); // a의 상태 출력 (kick과 punch가 각각 1씩 증가)
    b.show(); // b의 상태 출력 (a가 증가한 후의 값)
    b = a++; // 후위 증가 연산자 사용: a의 kick과 punch가 각각 1씩 증가하기 전의 값이 b에 저장된 후, a의 kick과 punch가 각각 1씩 증가
    a.show(); // a의 상태 출력 (kick과 punch가 각각 1씩 증가)
    b.show(); // b의 상태 출력 (a가 증가하기 전의 값)
}    