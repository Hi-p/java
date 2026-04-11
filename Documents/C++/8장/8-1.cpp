#include <iostream>
#include <string>
using namespace std;

class point { // 기본 클래스
    int x, y;
public:
    void set(int x, int y) { this ->x = x; this->y = y; }
    void showpoint() { cout << "(" << x << "," << y << ")" << endl; }
};

class colorpoint : public point { // point 클래스를 상속받는 colorpoint 클래스
    string color;
public:
    void setcolor(string color) { this->color = color; }
    void showcolorpoint();
};

void colorpoint::showcolorpoint() {
    cout << color << ": ";
    showpoint(); // point 클래스의 showpoint() 멤버 함수 호출
}

int main() {
    point p; // point 클래스(기본 클래스)의 객체 p 생성
    colorpoint cp; // colorpoint 클래스(파생 클래스)의 객체 cp 생성
    cp.set(3, 4); // point 클래스(기본 클래스)의 set() 멤버 함수 호출
    cp.setcolor("Red"); // colorpoint 클래스(파생 클래스)의 setcolor() 멤버 함수 호출
    cp.showcolorpoint(); // colorpoint 클래스(파생 클래스)의 showcolorpoint() 멤버 함수 호출
}