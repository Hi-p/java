#include <iostream>
using namespace std;

class rect; // 전방 선언

class rectmanager {
public:
    bool equals(rect r, rect s); // 멤버 함수 선언
};

class rect {
    int width, height;
public:
    rect(int width, int height) {this->width = width; this->height = height;} // 생성자, 자동 인라인 함수
    friend bool rectmanager::equals(rect r, rect s); // 친구 함수 선언
};

bool rectmanager::equals(rect r, rect s) { // 멤버 함수 구현
    if (r.width == s.width && r.height == s.height)
        return true;
    else
        return false;   
}

int main() {
    rect a(3, 4), b(3, 4); // 객체 생성
    rectmanager man; // 객체 생성

    if(man.equals(a, b)) // 멤버 함수 호출
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}