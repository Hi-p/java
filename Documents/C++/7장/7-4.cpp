#include <iostream>
using namespace std;

class power {
    int kick;
    int punch;
public:
    power(int kick=0, int punch=0) { // 생성자, 자동 인라인 함수, 디폴트 매개변수 사용
        this->kick = kick;
        this->punch = punch;
    }
    void show(); // 멤버 함수 선언
    power operator+(power op2); // 메버 함수로 선언해서 매개변수가 1개만 필요함
};

void power::show() { // 멤버 함수 구현
    cout << "kick: " << kick << ',' << " punch: " << punch << endl;
}

power power::operator+(power op2) {
    power tmp; // 새로운 객체 생성
    tmp.kick = kick + op2.kick; // 멤버 변수끼리 더하기
    tmp.punch = punch + op2.punch; // 멤버 변수끼리 더하기
    return tmp; // 객체 반환
}

int main() {
    power a(3, 5), b(4, 6), c; // 객체 생성
    c = a + b; // operator+ 멤버 함수 호출
    a.show(); // 멤버 함수 호출
    b.show(); // 멤버 함수 호출
    c.show(); // 멤버 함수 호출
}