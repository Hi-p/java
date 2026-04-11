#include <iostream>
using namespace std;

void fillline(int n = 25, char c = '*') { // 디폴트 매개 변수를 사용하는 함수
    for(int i = 0; i < n; i ++)
        cout << c;
    cout << endl;
}

int main() {
    fillline(); // 디폴트 매개 변수 사용
    fillline(10, '%'); // 디폴트 매개 변수 사용하지 않음
}