#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<int> qu; // int형을 저장하는 queue인 qu 선언
    qu.push(100);
    qu.push(200);
    qu.push(300);
    while(!qu.empty()) {
        cout << qu.front() << endl; // queue qu의 front 요소를 출력
        qu.pop(); // queue qu의 front 요소를 pop
    }
}