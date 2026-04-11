#include <iostream>
using namespace std;

class rect; // 전방 선언

class rectmanager {
public:
    bool equals(rect r, rect s); // 멤버 함수 선언
    void copy(rect &dest, rect &src); // 멤버 함수 선언
};

class rect {
    int width, height;
public:
    rect(int width, int height) {this->width = width; this->height = height;} // 생성자, 자동 인라인 함수
    friend rectmanager; // rectmanager 클래스 전체를 친구로 선언
};

bool rectmanager::equals(rect r, rect s) { // 멤버 함수 구현
    if (r.width == s.width && r.height == s.height)
        return true;
    else
        return false;   
}

void rectmanager::copy(rect &dest, rect &src) { // 멤버 함수 구현
    dest.width = src.width;
    dest.height = src.height;
}

int main() {
    rect a(3, 4), b(5, 6); // 객체 생성
    rectmanager man; // 객체 생성

    man.copy(b, a); // 멤버 함수 호출
    if(man.equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}