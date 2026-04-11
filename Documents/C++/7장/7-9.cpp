#include <iostream>
using namespace std;

class power {
    int kick;
    int punch;
public:
    power(int kick=0, int punch=0) { // 생성자 정의
        this->kick = kick;
        this->punch = punch;
    }
    void show(); // 멤버 함수 정의
    bool operator! (); // 논리 부정 연산자 오버로딩
};

void power::show() {
    cout << "kick: " << kick << ", punch: " << punch << endl;
}

bool power::operator! () {
    if (kick == 0 && punch == 0) {
        return true; // kick과 punch가 모두 0이면 true 반환
    }
    return false; // 그렇지 않으면 false 반환
}

int main() {
    power a(0, 0), b(5, 5); // power 객체 a와 b 생성
    if(!a)
        cout << "a의 파워가 0이다" << endl;
    else
        cout << "a의 파워가 0이 아니다" << endl;
    if(!b)
        cout << "b의 파워가 0이다" << endl;
    else
        cout << "b의 파워가 0이 아니다" << endl;
}