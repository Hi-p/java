#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> sv; // vector 객체 sv 생성
    string name; // string 객체 name 생성

    cout << "이름을 5개 입력하세요" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i+1 << " >> ";
        getline(cin, name); // name에 이름 입력
        sv.push_back(name); // vector 객체 sv에 name 추가
    }
    name = sv.at(0); // vector 객체 sv의 첫 번째 요소를 name에 저장
    for(int i = 0; i < sv.size(); i++) {
        if(name < sv[i]) { // name보다 sv[i]가 더 크면(사전순으로 뒤에 있으면)
            name = sv[i]; // name보다 sv[i]가 더 크면 name에 sv[i] 저장
        }
    }
    cout << "사전에서 가장 뒤에 나오는 이름은 " << name << endl;
}