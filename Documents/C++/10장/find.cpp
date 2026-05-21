#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string fruits[5] = {"사과", "토마토", "배", "수박", "키위"}; // 문자열 배열 fruits 생성 및 초기화
    vector<string> vec(&fruits[0], &fruits[5]); // 배열의 시작과 끝을 이용하여 벡터 vec 생성

    vector<string>::iterator it; // 벡터의 반복자 생성
    it = find(vec.begin(), vec.end(), "수박"); // 벡터에서 "수박"을 찾음

    if(it != vec.end()) {
        cout << "수박이 " << distance(vec.begin(), it) << "에 있습니다" << endl; // "수박"이 벡터의 몇 번째 위치에 있는지 출력
    }
}