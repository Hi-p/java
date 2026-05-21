#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* file = "/Users/edward/Documents/C++/12장/student.txt"; // 파일 경로를 상수 포인터로 선언, 파일 경로는 변경되지 않으므로 const 사용

    ifstream fin(file, ios::in | ios::binary);
    if(!fin) {
        cout << "열기 오류" << endl;
        return 0;
    }

    int count = 0;
    char s[32];
    while(!fin.eof()) {
        fin.read(s, 32); // 파일에서 32바이트씩 읽어서 s 배열에 저장, read() 함수는 파일에서 지정한 바이트 수만큼 읽어와서 버퍼에 저장
        int n = fin.gcount(); // read() 함수로 읽은 실제 바이트 수를 반환, gcount() 함수는 마지막으로 읽은 바이트 수를 반환
        cout.write(s, n); // 읽은 바이트 수만큼 s 배열의 내용을 출력, write() 함수는 버퍼에 저장된 내용을 지정한 바이트 수만큼 출력
        count += n;
    }

    cout << "읽은 바이트 수는 " << count << endl;
    fin.close();
}