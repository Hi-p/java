#include <iostream>
using namespace std;

int main() {
    cout.put('H');
    cout.put('i');
    cout.put(33); // 33이 ASCII 코드로 '!'에 해당하므로 '!'가 출력됩니다.
    cout.put('\n');

    cout.put('C').put('+').put('+').put(' ');

    char str[] = "I love programming";
    cout.write(str, 6); // str 배열의 처음부터 6글자만 출력합니다.
    cout << endl;
}