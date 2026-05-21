#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* srcfile = "/Users/edward/Documents/C++/12장/desert.jpg";
    const char* destfile = "/Users/edward/Documents/C++/12장/desert_copy.jpg";

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

    int c;
    while ((c = fsrc.get()) != EOF) {
        fdest.put(c);
    }
    cout << srcfile << "를 " << destfile << "로 복사 완료" << endl;
    fsrc.close();
    fdest.close();
}