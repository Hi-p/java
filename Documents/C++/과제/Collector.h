#ifndef COLLECTOR_H
#define COLLECTOR_H

class Collector {
    int *p;       // 데이터를 저장하는 힙 메모리의 주소를 담는 포인터
    int size = 0; // 배열의 크기

public:
    Collector(int size, int values[]); // 일반 생성자
    Collector(const Collector& src);   // 복사 생성자
    ~Collector();                      // 소멸자

    void show();                       // 데이터 출력
    int getSize() { return size; }     // size 반환
    int get(int index) { return p[index]; } // index번째 값 반환
};

// 외부 함수 선언
double calcAvg(Collector c);

#endif
