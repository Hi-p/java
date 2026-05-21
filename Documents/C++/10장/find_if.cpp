#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool checkkim(string s) {
    if (s.find("김") != string::npos) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string names[5] = {"김철수", "박문수", "강감찬", "김유신", "이순신"}; // 문자열 배열 names 생성 및 초기화
    vector<string> vec(&names[0], &names[5]); //배열 -> 벡터로 변환

    vector<string>::iterator it; // 벡터의 반복자 생성
    it = vec.begin();

    while (true) {
        it = find_if(it, vec.end(), checkkim); // 벡터에서 checkkim 함수를 사용해서 "김"이 포함된 문자열을 찾음
        if (it == vec.end()) {
            break;
        }
        cout << "위치 " << distance(vec.begin(), it) << "에서 " << *it << "를 탐색하였음" << endl;
        it++;
    }
}