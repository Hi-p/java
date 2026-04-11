#include <iostream>
#include <string>
using namespace std;

void star(int a = 5); // a의 기본값이 5인 원형 함수 star 선언
void msg(int id, string text = ""); // id는 필수 매개변수, text는 기본값이 ""인 원형 함수 msg 선언

void star(int a) {
    for (int i = 0; i < a; i++) {
        cout << "*";
    }
    cout << endl;
}

void msg(int id, string text) {
    cout << id << ' ' << text << endl;
}

int main() {
    star(); // 기본값이 5인 star 함수 호출
    star(10); // a의 값이 10인 star 함수 호출
    msg(10); // id의 값이 10이고 text의 기본값이 ""인 msg 함수 호출
    msg(10, "Hello"); // id의 값이 10이고 text의 값이 "Hello"인 msg 함수 호출
}