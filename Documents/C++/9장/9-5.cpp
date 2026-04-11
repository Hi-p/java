#include <iostream>
using namespace std;

class base {
public:
    virtual ~base() {
        cout << "~Base()" << endl;
    }
};

class derived : public base {
public:
    ~derived() {
        cout << "~Derived()" << endl;
    }
};

int main() {
    derived *dp = new derived(); // derived 객체 생성, derived 포인터로 참조
    base *bp = new derived(); // derived 객체 생성, base 포인터로 참조, 업캐스팅
    delete dp; // derived 객체 소멸
    delete bp; // base 포인터를 통해 derived 객체 소멸
}