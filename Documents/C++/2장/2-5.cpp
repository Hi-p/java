#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char passwd[11]; // 비밀번호를 저장할 배열 선언 (최대 10자 + null 문자)
    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while(true) {
        cout << "암호 >> ";
        cin >> passwd; // 사용자로부터 암호 입력 받기
        if (strcmp(passwd, "C++") == 0) { // 입력된 암호가 "C++"과 일치하는지 비교
            cout << "프로그램을 정상적으로 종료합니다" << endl;
            break; // 암호가 일치하면 루프 종료
        }
        else {
            cout << "암호가 틀립니다~~" << endl; // 암호가 틀리면 메시지 출력
        }
    }
}