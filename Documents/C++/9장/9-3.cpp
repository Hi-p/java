#include <iostream>
using namespace std;

class base {
public:
    virtual void f() {
        cout << "Base::f() called" << endl;
    }
};

class derived : public base {
public:
    void f() { // virtual 키워드 생략함, virtual void f()와 동일하게 가상 함수로 간주됨
        cout << "Derived::f() called" << endl;
    }
};

class grandderived : public derived {
public:
    void f() { // virtual 키워드 생략함, virtual void f()와 동일하게 가상 함수로 간주됨
        cout << "Grandderived::f() called" << endl;
    }
};

int main() {
    grandderived g; // grandderived 클래스의 객체 g 선언
    base *bp; // base 클래스의 포인터 bp 선언
    derived *dp; // derived 클래스의 포인터 dp 선언
    grandderived *gp; // grandderived 클래스의 포인터 gp 선언

    bp = dp = gp = &g; // 포인터 bp, dp, gp가 모두 객체 g를 가리킴, 업 캐스팅이 일어남
    bp->f(); // 포인터 bp를 통해 f() 호출, grandderived::f()가 호출됨
    dp->f(); // 포인터 dp를 통해 f() 호출, grandderived::f()가 호출됨
    gp->f(); // 포인터 gp를 통해 f() 호출, grandderived::f()가 호출됨
}