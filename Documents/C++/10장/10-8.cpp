#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // int형을 저장하는 벡터 v 생성
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it; // 벡터 v의 원소에 접근하기 위한 포인터 it 선언

    for (it = v.begin(); it != v.end(); it++) {
        int n = *it;
        n = n * 2;
        *it = n;
    }

    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}