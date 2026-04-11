#include <iostream>
using namespace std;

class rect; // 전방 선언
bool equals(rect r, rect s); // 외부함수(전역함수)선언

class rect {
    int width, height;
public:
    rect(int width, int height) {this->width = width; this->height = height;} // 생성자, 자동 인라인 함수
    friend bool equals(rect r, rect s); // 외부함수(전역함수)를 친구로 선언
};

bool equals(rect r, rect s) { // 외부함수(전역함수) 구현
    if (r.width == s.width && r.height == s.height)
        return true;
    else
        return false;
}

int main() {
    rect a(3, 4), b(4, 5);
    if(equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}