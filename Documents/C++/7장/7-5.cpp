#include <iostream>
using namespace std;

class power {
    int kick, punch; // 멤버 변수 선언
public:
    power(int kick=0, int punch=0) { // 생성자, 자동 인라인 함수, 디폴트 매개변수 사용
        this->kick = kick; // 멤버 변수 초기화
        this->punch = punch; // 멤버 변수 초기화
    }
    void show(); // 멤버 함수 선언
    bool operator==(power op2); // 멤버 함수로 선언해서 매개변수가 1개만 필요함
};

void power::show() { // 멤버 함수 구현
    cout <<"kick = " << kick << ',' << " punch = " << punch << endl;
}

bool power::operator==(power op2) {
    if (kick == op2.kick && punch == op2.punch) // 멤버 변수끼리 비교
        return true; // 같으면 true 반환
    else
        return false; // 다르면 false 반환
}

int main() {
    power a(3, 5), b(3, 5); // 객체 생성
    a.show(); // 멤버 함수 호출
    b.show(); // 멤버 함수 호출
    if (a == b) // operator== 멤버 함수 호출
        cout << "두 파워가 같다" << endl;
    else
        cout << "두 파워가 같지 않다" << endl;
}