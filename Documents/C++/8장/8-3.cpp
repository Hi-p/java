#include <iostream>
#include <string>
using namespace std;

class tv {
    int size; // 멤버 변수 선언
public:
    tv() { size = 20;} // 기본 생성자 선언 및 구현
    tv(int size) { this->size = size; } // 매개변수가 있는 생성자 선언 및 구현
    int getsize() { return size; } // 멤버 함수 선언 및 구현
};

class widetv : public tv { // tv 클래스를 상속받는 widetv 클래스
    bool videoln; // 멤버 변수 선언
public: // 매개변수가 있는 생성자 선언 및 구현
    widetv(int size, bool videoln) : tv(size) { 
        this->videoln = videoln;
    }
    bool getvideoln() { return videoln; } // 멤버 함수 선언 및 구현
};

class smarttv : public widetv { // widetv 클래스를 상속받는 smarttv 클래스
    string ipaddr; // 멤버 변수 선언
public: // 매개변수가 있는 생성자 선언 및 구현
    smarttv(string ipaddr, int size) : widetv(size, true) {
        this->ipaddr = ipaddr;
    }
    string getipaddr() { return ipaddr; } // 멤버 함수 선언 및 구현
};

int main() {
    smarttv htv("202.31.247.145", 32); // smarttv 클래스의 객체 htv 생성 및 매개변수가 있는 생성자 호출
    cout << "size= " << htv.getsize() << endl; // tv 클래스의 getsize() 멤버 함수 호출
    cout << "videoln= " << boolalpha << htv.getvideoln() << endl; // widetv 클래스의 getvideoln() 멤버 함수 호출
    cout << "IP= " << htv.getipaddr() << endl; // smarttv 클래스의 getipaddr() 멤버 함수 호출
}