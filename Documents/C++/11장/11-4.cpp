#include <iostream>
using namespace std;

int main() {
    char line[80];
    cout << "cin.getline() 함수로 라인을 읽습니다." << endl;
    cout << "exit을 입력하면 루프가 끝납니다." << endl;

    int no = 1; // 라인 번호
    while(true) {
        cout << "라인 " << no << " >> ";
        cin.getline(line, 80);
        if(strcmp(line, "exit") == 0) { // strcmp() 함수 = 문자열 비교 함수, 같으면 0을 반환
            break;
        }
        cout << "echo -- > " ;
        cout << line << endl;
        no++;
    }
}