#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[10], dept[20]; // 이름, 학과
    int sid; // 학번

    cout << "이름 >> ";
    cin >> name;
    cout << "학번 >> ";
    cin >> sid;
    cout << "학과 >> ";
    cin >> dept;

    ofstream fout("/Users/edward/Documents/C++/12장/student.txt"); // = ofstream fout; fout.open("/Users/edward/Documents/C++/12장/student.txt"); , 파일 열기
    if (!fout) { // 파일 열기 실패
        cout << "/Users/edward/Documents/C++/12장/student.txt 파일을 열 수 없습니다.";
        return 0; // 프로그램 종료
    }

    fout << name << endl;
    fout << sid << endl;
    fout << dept << endl;

    fout.close(); // 파일 닫기
}