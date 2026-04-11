#include <iostream>
#include <string>
using namespace std;

int main() {
    string str; // 빈 문자열을 가진 str 변수를 선언
    string address("서울시 성북구 삼선동 389"); // 주소를 초기화하는 문자열 변수 선언
    string copyAddress(address); // address의 문자열을 복사한 copyAddress 변수 선언

    char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'}; // C - 스트링 배열 선언
    string title(text); // text 배열을 이용하여 title 문자열 변수 선언

    cout << str << endl; // 빈 문자열 출력
    cout << address << endl; // 주소 출력
    cout << copyAddress << endl; // 복사된 주소 출력
    cout << title << endl; // title 출력
}