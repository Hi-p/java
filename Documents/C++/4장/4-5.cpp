#include <iostream>
using namespace std;

int main() {
    int *p; // int 타입의 포인터 변수 p 선언
    p = new int; // int 타입의 메모리를 동적으로 할당하여 p가 가리키도록 함, 힙 메모리에 int 크기의 공간이 할당됨
    if(!p) {
        cout << "메모리 할당 실패" << endl; // 메모리 할당 실패 시 메시지 출력
        return 0; // 프로그램 종료
    }

    *p = 5; // p가 가리키는 메모리(int 공간)에 5를 저장
    int n = *p; // p가 가리키는 메모리에서 값을 읽어와 n에 저장
    cout << "*p = " << *p << endl; // p가 가리키는 메모리의 값을 출력
    cout << "n = " << n << endl; // n의 값을 출력

    delete p; // 동적으로 할당된 메모리를 반환하여 메모리 누수 방지
}