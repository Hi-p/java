#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* file = "/Users/edward/Documents/C++/12장/student.txt"; // 파일 경로를 상수 포인터로 선언, 파일 경로는 변경되지 않으므로 const 사용

    ifstream fin(file);
    if(!fin) {
        cout << file << "열기 오류" << endl;
        return 0;
    }

    int count = 0;
    int c;
    while ((c = fin.get()) != EOF) {
        cout << (char)c; // 파일에서 읽은 문자를 출력, get() 함수는 파일에서 한 문자씩 읽어와서 정수형으로 반환, EOF는 파일의 끝을 나타내는 상수
        count++;
    }
    cout << endl;
    cout << "읽은 바이트 수는 " << count << endl;
    fin.close();
}