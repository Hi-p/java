#include <iostream>
using namespace std;

class Collector {
    int *p;      // 데이터를 저장하는 힙 메모리의 주소를 담는 포인터
    int size = 0; // 배열의 크기

public:
    // ① 일반 생성자
    // size: 배열 크기, values[]: 저장할 데이터 배열
    Collector(int size, int values[]) {
        this->size = size;          // 매개변수 size를 멤버변수 size에 저장
        p = new int[size];          // 힙에 size 크기의 배열 동적 할당
        for (int i = 0; i < size; i++)
            p[i] = values[i];       // values의 값을 p 배열에 하나씩 복사
    }

    // ② 복사 생성자
    // 객체를 함수에 값으로 전달할 때 자동으로 호출됨
    // const Collector& src: 원본 객체를 참조로 받음 (복사 없이 원본 접근)
    Collector(const Collector& src) {
        this->size = src.size;      // size는 숫자라 그냥 복사해도 OK
        p = new int[size];          // 새로운 힙 메모리 별도로 할당 (깊은 복사 핵심!)
        for (int i = 0; i < size; i++)
            p[i] = src.p[i];        // 원본 값을 새 공간에 하나씩 복사
    }

    // ③ 소멸자
    // 객체가 사라질 때 자동으로 호출됨
    ~Collector() {
        delete[] p;                 // 동적 할당한 힙 메모리 반환
    }

    // ④ show()
    // 데이터 개수와 배열 값을 화면에 출력
    void show() {
        cout << "데이터 수 " << size << ": ";
        for (int i = 0; i < size; i++)
            cout << p[i] << " ";
        cout << endl;
    }

    int getSize() { return size; }      // size 반환
    int get(int index) { return p[index]; } // index번째 값 반환
};

// ⑤ 외부 함수 calcAvg()
// Collector 객체를 받아 평균값 계산
// calcAvg(weight) 호출 시 → 복사 생성자 자동 호출!
double calcAvg(Collector c) {
    double sum = 0;
    for (int i = 0; i < c.getSize(); i++)
        sum += c.get(i);            // get()으로 값을 하나씩 더함
    return sum / c.getSize();       // 합계 / 개수 = 평균
}   // 함수 끝 → c 소멸 → c만의 힙 메모리 해제 (weight에 영향 없음!)

int main() {
    int temp[] = { 69, 70, 71, 72, 74 };
    Collector weight(4, temp);      // 일반 생성자 호출, size=4라 69~72만 저장
    double avg = calcAvg(weight);   // 복사 생성자 호출! weight → c로 깊은 복사
    weight.show();                  // 정상 출력 (복사 생성자 덕분에 메모리 안전)
    cout << "평균은 " << avg << endl; // 70.5 출력
}   // main 끝 → weight 소멸 → weight 힙 메모리 정상 해제