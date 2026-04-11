#include <iostream>
using namespace std;

class shape {
public:
    virtual void draw() {
        cout << "--shape--";
    }
};

class circle : public shape {
public:
    void draw() {
        shape::draw();
        cout << "circle" << endl;
    }
};

int main() {
    circle c; // circle 객체 생성
    shape *pShape = &c; // shape 포인터로 circle 객체 참조, 업캐스팅
    pShape->draw(); // circle 클래스의 draw() 함수 호출, 가상 함수이므로 동적 바인딩
    pShape->shape::draw(); // shape 클래스의 draw() 함수 호출
}