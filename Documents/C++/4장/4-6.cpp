#include <iostream>
using namespace std;

int main() {
    cout << "입력할 정수의 개수는 ? "; 
    int n; 
    cin >> n; // 입력할 정수의 개수를 입력받는다.
    if(n <= 0) 
        return 0; // 입력할 정수의 개수가 0 이하이면 프로그램을 종료한다.
    int *p = new int[n]; // 입력할 정수의 개수만큼 동적 배열을 할당한다.
    if(!p) {
        cout << "메모리 할당 실패" << endl; // 메모리 할당에 실패하면 오류 메시지를 출력한다.
        return 0; // 프로그램을 종료한다.
    }

    for(int i = 0; i < n; i++) {
        cout << i + 1 << "번째 정수: ";
        cin >> p[i]; // 입력한 정수를 동적 배열에 저장한다.
    }

    int sum = 0;
    for(int i = 0; i < n; i++) 
        sum += p[i]; // 동적 배열에 저장된 정수들의 합을 계산한다.
    cout << "평균 " << sum / n << endl; // 계산된 평균을 출력한다.

    delete [] p; // 동적 배열을 반환한다.
}