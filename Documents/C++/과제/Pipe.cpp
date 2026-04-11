#include <iostream>
using namespace std;

// Pipe 클래스 선언부
class Pipe {
    int data[10]; // 파이프 내 저장 공간
    int index;    // 도착하는 정수를 저장할 위치 (현재 저장된 데이터의 개수)
public:
    Pipe();             // 생성자
    int arrive(int n);  // 데이터 삽입
    int shift();        // 데이터 한 칸씩 이동
    void show();        // 전체 출력
};

// Pipe 클래스 구현부

// 1. 생성자: 배열을 모두 0으로, index를 0으로 초기화
Pipe::Pipe() {
    for(int i = 0; i < 10; i++) {
        data[i] = 0;
    }
    index = 0;
}

// 2. arrive 함수: 데이터 삽입 및 밀어내기
int Pipe::arrive(int n) {
    if (index == 10) { 
        // 꽉 차 있을 때: 맨 앞 데이터(data[0])를 백업하고 모두 한 칸씩 당김
        int front = data[0];
        for(int i = 0; i < 9; i++) {
            data[i] = data[i + 1];
        }
        data[9] = n; // 맨 뒤에 새로운 값 삽입
        return front; // 밀려난 맨 앞 데이터 리턴
    } else {
        // 꽉 차 있지 않을 때: index 위치에 넣고 index 증가
        data[index] = n;
        index++;
        return -1;
    }
}

// 3. shift 함수: 강제로 한 칸씩 당기고 맨 뒤에 0 넣기
int Pipe::shift() {
    int front = data[0];
    for(int i = 0; i < 9; i++) {
        data[i] = data[i + 1];
    }
    data[9] = 0; // 맨 뒤를 빈 공간(0)으로 처리
    return front;
}

// 4. show 함수: 배열 전체 출력
void Pipe::show() {
    cout << "파이프 내부 [";
    for(int i = 0; i < 10; i++) {
        cout << data[i];
        if (i < 9) cout << " "; // 숫자 사이에만 공백 출력
    }
    cout << "]" << endl;
}

// 메인 함수 
int main() {
    Pipe pipe; // Pipe 객체 생성
    for (int i = 0; i < 6; i++) {
        pipe.arrive(i); // 0~5 삽입
    }
    pipe.show();
    
    for (int i = 6; i < 12; i++) {
        pipe.arrive(i); // 6~11 삽입 (9넘어가면 밀어내기 시작)
    }
    pipe.show();
    
    int front = pipe.shift(); // 맨 앞 데이터 뽑고 이동
    cout << "shift()로 제거된 맨 앞 데이터 : " << front << endl;
    pipe.show();
    
    front = pipe.arrive(50); // 50 삽입
    cout << "arrive(50)로 제거된 맨 앞 데이터 : " << front << endl;
    pipe.show();
    
    return 0;
}