#include <iostream>
using namespace std;

class base {
public:
    void f() { cout << "Base::f() callde" << endl;}
};

class derived : public base {
public:
    void f() { cout << "Derived::f() callde" << endl;}
};

int main() {
    derived d, *pDer; // 객체 d와 포인터 pDer 선언
    pDer = &d; // 포인터 pDer이 객체 d를 가리킴
    pDer->f(); // 포인터 pDer을 통해 f() 호출

    base *pBase; // 포인터 pBase 선언
    pBase = pDer; // 업 캐스팅: 포인터 pBase가 포인터 pDer이 가리키는 객체를 가리킴, 즉, pBase는 d 객체 주소를 가리킴
    pBase->f(); // 포인터 pBase를 통해 f() 호출
}