#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> my_set; // int형을 저장하는 my_set 선언
    
    my_set.insert(1);
    my_set.insert(2);
    my_set.insert(3);

    set<int>::iterator pos = my_set.find(2); // set<int>의 iterator 선언, find() 함수를 이용하여 2의 위치를 pos에 저장
    if (pos != my_set.end()) {
        cout << "값 " << *pos << "가 발견되었음" << endl; // pos가 my_set의 끝이 아니라면, pos가 가리키는 값을 출력
    }
    else {
        cout << "값이 발견되지 않았음" << endl; // pos가 my_set의 끝이라면, 값이 발견되지 않았음을 출력
    }
}