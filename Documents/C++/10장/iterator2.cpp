#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec; // int형을 저장하는 벡터 vec 생성
    for(int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    vector<int>::reverse_iterator rit; // 벡터의 반복자 생성
    for(rit = vec.rbegin(); rit != vec.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << endl;
}