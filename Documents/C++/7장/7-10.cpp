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
    power operator++ (int x); // 후위 증가 연산자 오버로딩
};

void power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

power power::operator++ (int x) {
    power tmp = *this; // 현재 객체의 값을 임시 객체에 저장
    kick++; // kick 값을 증가
    punch++; // punch 값을 증가
    return tmp; // 증가하기 전의 값을 반환
}

int main() {
    power a(3, 5), b; // 객체 생성
    a.show(); // a의 현재 상태 출력
    b.show(); // b의 현재 상태 출력
    b = a++; // a를 후위 증가 연산자로 증가시키고, 증가하기 전의 값을 b에 저장
    a.show(); // a의 상태 출력 (증가된 값)
    b.show(); // b의 상태 출력 (증가하기 전의 값)
}