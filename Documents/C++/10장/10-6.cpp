#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // vector 객체 v 생성
    
    v.push_back(1); // vector 객체 v에 1 추가
    v.push_back(2); // vector 객체 v에 2 추가
    v.push_back(3); // vector 객체 v에 3 추가

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // vector 객체 v의 요소 출력
    }
    cout << endl;

    v[0] = 10; // vector 객체 v의 첫 번째 요소를 10으로 변경
    int n = v[2]; // vector 객체 v의 세 번째 요소를 n에 저장
    v.at(2) = 5; // vector 객체 v의 세 번째 요소를 5로 변경

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; // vector 객체 v의 요소 출력
    }
    cout << endl;
}