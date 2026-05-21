#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* firstfile = "/Users/edward/Documents/C++/12장/student.txt"; // 첫 번째 파일 경로
    const char* secondfile = "/etc/hosts"; // 두 번째 파일 경로

    fstream fout(firstfile, ios::out | ios::app); // 첫 번째 파일을 쓰기 모드로 열고, 기존 내용에 추가, 덧붙인다는게 firstfile에 쓴다는 의미니까 ios::out인거임
    if(!fout) {
        cout << firstfile << "열기 오류";
        return 0;
    }

    fstream fin(secondfile, ios::in);
    if(!fin) {
        cout << secondfile << "열기 오류";
        return 0;
    }

    int c;
    while ((c = fin.get()) != EOF) {
        fout.put(c); // 두 번째 파일에서 읽은 문자를 첫 번째 파일에 쓰기, put() 함수는 파일에 한 문자씩 쓰는 함수
    }

    fin.close();
    fout.close();
}