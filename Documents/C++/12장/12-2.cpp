#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin; // 파일 입력 스트림 객체 생성, 파일에서 데이터를 읽어올 때 사용
    fin.open("/Users/edward/Documents/C++/12장/student.txt");
    // = ifstream fin("/Users/edward/Documents/C++/12장/student.txt");
    if(!fin) { // 파일 열기 실패
        cout << "파일을 열 수 없습니다";
        return 0;
    }

    char name[10], dept[20];
    int sid;
    
    fin >> name; // 파일에서 이름 읽어와서 name 배열에 저장
    fin >> sid; // 파일에서 학번 읽어와서 sid 변수에 저장
    fin >> dept; // 파일에서 학과 읽어와서 dept 배열에 저장

    cout << name << endl;
    cout << sid << endl;
    cout << dept << endl;

    fin.close();
}