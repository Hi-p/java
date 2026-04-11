#include <iostream>
using namespace std;

int main() {
    cout << "이름을 입력하세요 >> ";

    char name[11]; // 이름을 저장할 배열 선언 (최대 10자 + null 문자)
    cin >> name; // 사용자로부터 이름 입력 받기

    cout << "이름은 " << name << "입니다\n"; // 입력된 이름을 출력
}