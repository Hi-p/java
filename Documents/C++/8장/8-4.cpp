#include <iostream>
using namespace std;

class adder {
protected:
    int add(int a, int b) { return a + b; } // 멤버 함수 선언 및 구현(인라인 자동 함수) 
};

class subtracter {
protected:
    int minus(int a, int b) { return a - b; } // 멤버 함수 선언 및 구현(인라인 자동 함수)
};

class calculator : public adder, public subtracter {
public:
    int calc(char op, int a, int b); // 멤버 함수 선언
};

int calculator::calc(char op, int a, int b) { // 멤버 함수 구현
    int res = 0;
    switch(op) {
        case '+': res = add(a, b);
            break;
        case '-': res = minus(a, b);
            break;
    }
    return res;
}

int main() {
    calculator handcalculator; // calculator 클래스의 객체 handcalculator 생성
    cout << "2 + 4 = " << handcalculator.calc('+', 2, 4) << endl; // calculator 클래스의 calc() 멤버 함수 호출
    cout << "100 - 8 = " << handcalculator.calc('-', 100, 8) << endl; // calculator 클래스의 calc() 멤버 함수 호출
}