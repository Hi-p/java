#include <iostream>
#include <string>
using namespace std;

int main() {
    string song("Falling in love with you"); // 문자열 초기화
    string elvis("Elvis Presley"); // 문자열 초기화
    string singer; // 빈 문자열 선언

    cout << song + "를 부른 가수는";
    cout << "(힌트 : 첫 글자는 " << elvis[0] << ")?";

    getline(cin, singer); // 사용자로부터 가수 이름 입력 받기 
    if (singer == elvis) { // 문자열 비교
        cout << "정답입니다" << endl;
    }
    else {
        cout << "틀렸습니다. " + elvis + "입니다." << endl; 
    }
}