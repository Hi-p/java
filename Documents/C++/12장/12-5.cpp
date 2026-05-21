#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("/Users/edward/Documents/C++/12장/student.txt"); // 파일 입력 스트림 객체 생성과 동시에 파일 열기
    if(!fin) {
        cout << "열기 실패" << endl;
        return 0;
    }

    char buf[81];
    while (fin.getline(buf, 80)) {
        cout << buf << endl;
    }

    fin.close();
}