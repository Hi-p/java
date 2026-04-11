#include <iostream>
using namespace std;

int main() {
    cout << "너비를 입력하세요 >> ";

    int width; // 너비를 저장할 변수 선언
    cin >> width; // 사용자로부터 너비 입력 받기
    cout << "높이를 입력하세요 >> ";
    int height; // 높이를 저장할 변수 선언
    cin >> height; // 사용자로부터 높이 입력 받기
    int area = width * height; // 너비와 높이를 곱하여 면적 계산
    cout << "면적은 " << area << "\n"; // 계산된 면적을 출력
}