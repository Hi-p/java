#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;

    cout << "5개의 정수를 입력하세요 >> ";
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end()); // 벡터 v의 원소들을 오름차순으로 정렬

    vector<int>::iterator it; // 벡터 v의 원소에 접근하기 위한 포인터 it 선언

    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}