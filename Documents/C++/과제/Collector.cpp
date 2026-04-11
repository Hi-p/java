#include <iostream>
#include "Collector.h"
using namespace std;

// ① 일반 생성자
Collector::Collector(int size, int values[]) {
    this->size = size;          // 매개변수 size를 멤버변수 size에 저장
    p = new int[size];          // 힙에 size 크기의 배열 동적 할당
    for (int i = 0; i < size; i++)
        p[i] = values[i];       // values의 값을 p 배열에 하나씩 복사
}

// ② 복사 생성자
// calcAvg(weight) 호출 시 자동으로 호출됨
Collector::Collector(const Collector& src) {
    this->size = src.size;      // size는 숫자라 그냥 복사해도 OK
    p = new int[size];          // 새로운 힙 메모리 별도로 할당 (깊은 복사 핵심!)
    for (int i = 0; i < size; i++)
        p[i] = src.p[i];        // 원본 값을 새 공간에 하나씩 복사
}

// ③ 소멸자
// 객체가 사라질 때 자동으로 호출됨
Collector::~Collector() {
    delete[] p;                 // 동적 할당한 힙 메모리 반환
}

// ④ show()
void Collector::show() {
    cout << "데이터 수 " << size << ": ";
    for (int i = 0; i < size; i++)
        cout << p[i] << " ";
    cout << endl;
}

// ⑤ 외부 함수 calcAvg()
// 호출 시 복사 생성자 자동 실행 → weight와 독립된 메모리 생성
double calcAvg(Collector c) {
    double sum = 0;
    for (int i = 0; i < c.getSize(); i++)
        sum += c.get(i);
    return sum / c.getSize();
}   // 함수 끝 → c 소멸 → c만의 힙 메모리 해제 (weight에 영향 없음!)
