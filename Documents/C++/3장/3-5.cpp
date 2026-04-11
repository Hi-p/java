#include <iostream>
using namespace std;

class rectangle {
public:
    int width, height; // 2개의 멤버 변수 선언

    rectangle(); // 기본 생성자 선언
    rectangle(int w, int h); // 매개변수가 있는 생성자 선언
    rectangle(int length); // 정사각형을 위한 매개변수가 있는 생성자 선언
    bool isSquare(); // 정사각형인지 판별하는 멤버 함수 선언
};

rectangle::rectangle() {
    width = height = 1; // 기본 생성자에서 width와 height를 1로 초기화
}

rectangle::rectangle(int w, int h) { 
    width = w; // 매개변수가 있는 생성자에서 width와 height를 각각 w와 h로 초기화
    height = h; 
}

rectangle::rectangle(int length) { 
    width = height = length; // 정사각형을 위한 매개변수가 있는 생성자에서 width와 height를 length로 초기화
}

bool rectangle::isSquare() {
    if (width == height) { // width와 height가 같으면 정사각형이므로 true 반환
        return true;
    }
    else { // width와 height가 다르면 정사각형이 아니므로 false 반환
        return false;
    }
}

int main() {
    rectangle rect1;
    rectangle rect2(3, 5); 
    rectangle rect3(3);

    if (rect1.isSquare())
        cout << "rect1은 정사각형이다." << endl;
    if (rect2.isSquare())
        cout << "rect2는 정사각형이다." << endl;
    if (rect3.isSquare())
        cout << "rect3은 정사각형이다." << endl;
}