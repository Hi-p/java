#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    priority_queue<int> pq; // int형을 저장하는 priority_queue인 pq 선언
    pq.push(100);
    pq.push(200);
    pq.push(300);
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}