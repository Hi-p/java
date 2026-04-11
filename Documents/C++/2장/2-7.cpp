#include <iostream>
using namespace std;

int main() {
    char line[100]; // 최대 99자 + null 문자
    cout << "문자열을 입력하세요 >> ";
    cin.getline(line, 100, '\n'); // 줄 단위로 입력 받기

    int count = 0; // 단어 수를 세기 위한 변수
    int i = 0; // 배열의 인덱스

    while (line[i] != '\0') {
        if (line[i] == 'e')
            count++; // 'e'가 나타날 때마다 카운트 증가
        i++; // 다음 문자로 이동
    }
    cout << "총 글자수 " << i << ", 문자 e의 개수 " << count << "개" << endl;
}