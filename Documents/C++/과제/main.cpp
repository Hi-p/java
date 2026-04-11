#include <iostream>
#include "Collector.h"
using namespace std;

int main() {
    int temp[] = { 69, 70, 71, 72, 74 };
    Collector weight(4, temp);      // 일반 생성자 호출, size=4라 69~72만 저장
    double avg = calcAvg(weight);   // 복사 생성자 호출! weight → c로 깊은 복사
    weight.show();                  // 정상 출력
    cout << "평균은 " << avg << endl; // 70.5 출력
}   // main 끝 → weight 소멸 → weight 힙 메모리 정상 해제
