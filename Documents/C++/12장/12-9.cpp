#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* srcfile = "/Users/edward/Documents/C++/12장/tulips.jpg";
    const char* destfile = "/Users/edward/Documents/C++/12장/tulips_copy.jpg";

    ifstream fsrc(srcfile, ios::in | ios::binary);
    if(!fsrc) {
        cout << srcfile << "열기 오류" << endl;
        return 0;
    }

    ofstream fdest(destfile, ios::out | ios::binary);
    if(!fdest) {
        cout << destfile << "열기 오류" << endl;
        return 0;
    }

    char s[1024];
    int count = 0;
    while (!fsrc.eof()) {
        fsrc.read(s, 1024);
        int n = fsrc.gcount();
        fdest.write(s, n);
        count += n;
    }
    cout << srcfile << "를 " << destfile << "로 복사 완료" << endl;
    cout << "읽은 바이트 수 " << count << endl;
    fsrc.close();
    fdest.close();
}