#include <iostream>
using namespace std;

int sum(int a, int b) { // a부터 b까지의 합을 반환하는 함수
    int s = 0;
    for (int i = a; i <= b; i++) {
        s += i;
    }
    return s;
}

int sum(int a) { // 0부터 a까지의 합을 반환하는 함수
    int s = 0;
    for (int i = 0; i <= a; i++) {
        s += i;
    }
    return s;
}

int main() {
    cout << sum(3, 5) << endl; // 3부터 5까지의 합 출력
    cout << sum(3) << endl; // 0부터 3까지의 합
    cout << sum(100) << endl; // 0부터 100까지의 합
}