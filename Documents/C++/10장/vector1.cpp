#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> scores(10); // 크기가 10인 double형 벡터 생성

    for (int i = 0; i < scores.size(); i++) {
        cout << "성적을 입력하시오: ";
        cin >> scores[i]; // 벡터의 각 요소에 성적 입력
    }

    double highest = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > highest) {
            highest = scores[i]; // 가장 높은 성적 업데이트
        }
    }
    cout << "최고 성적은 " << highest << "입니다" << endl;
}