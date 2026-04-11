#include <iostream>
using namespace std;

int big(int a, int b) { // a와 b 중 큰 값을 반환하는 함수
    if (a > b) 
        return a;
    else
        return b;
}

int big(int a[], int size) { // a 배열에서 가장 큰 값을 반환하는 함수
    int res = a[0];
    for(int i = 1; i < size; i++) 
        if(res < a[i])
            res = a[i];
    return res;
}

int main() {
    int array[5] = {1, 9, -2, 8, 6};
    cout << big(2,3) << endl; // 2와 3 중 큰 값 출력
    cout << big(array, 5) << endl; // array 배열에서 가장 큰 값
}