#include <iostream>
#include <string>
using namespace std;

class point {
protected: // protected 접근 지정자 사용
    int x, y; // 멤버 변수 선언
public:
    void set(int x, int y); // 멤버 함수 선언
    void showpoint(); // 멤버 함수 선언
};

void point::set(int x, int y) { // 멤버 함수 구현
    this->x = x;
    this->y = y;
}

void point::showpoint() { // 멤버 함수 구현
    cout << "(" << x << "," << y << ")" << endl;
}

class colorpoint : public point {
    string color; // 멤버 변수 선언
public:
    void setcolor(string color); // 멤버 함수 선언
    void showcolorpoint(); // 멤버 함수 선언
    bool equals(colorpoint p); // 멤버 함수 선언
};

void colorpoint::setcolor(string color) { // 멤버 함수 구현
    this->color = color;
}

void colorpoint::showcolorpoint() {
    cout << color << ": ";
    showpoint(); // point 클래스의 showpoint() 멤버 함수 호출
}

bool colorpoint::equals(colorpoint p) {
    if (x == p.x && y == p.y && color == p.color) 
        return true;
    else
        return false;
}

int main() {
    point p; // point 클래스의 객체 p 생성
    p.set(3, 4); // point 클래스의 set() 멤버 함수 호출
    // p.x = 5; // point 클래스의 멤버 변수 x에 직접 접근 (protected 접근 지정자 사용으로 인해 오류 발생)
    // p.y = 5; // point 클래스의 멤버 변수 y에 직접 접근 (protected 접근 지정자 사용으로 인해 오류 발생)
    p.showpoint(); // point 클래스의 showpoint() 멤버 함수 호출

    colorpoint cp; // colorpoint 클래스의 객체 cp 생성
    // cp.x = 10; // point 클래스의 멤버 변수 x에 직접 접근 (protected 접근 지정자 사용으로 인해 오류 발생)
    // cp.y = 10; // point 클래스의 멤버 변수 y에 직접 접근 (protected 접근 지정자 사용으로 인해 오류 발생)
    cp.set(3, 4); // point 클래스의 set() 멤버 함수
    cp.setcolor("red"); // colorpoint 클래스의 setcolor() 멤버 함수
    cp.showcolorpoint(); // colorpoint 클래스의 showcolorpoint() 멤버 함수 호출

    colorpoint cp2; // colorpoint 클래스의 객체 cp2 생성
    cp2.set(3, 4); // point 클래스의 set() 멤버
    cp2.setcolor("red"); // colorpoint 클래스의 setcolor() 멤버 함수
    cout << ((cp.equals(cp2)) ? "true" : "false") << endl; // colorpoint 클래스의 equals() 멤버 함수 호출, 삼항 연산자 사용
}