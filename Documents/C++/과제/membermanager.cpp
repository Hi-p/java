#include <iostream>
#include <string>
using namespace std;

// 1. 회원 정보를 담는 Member 클래스
class Member {
    string name;
    int point;
public:
    // 디폴트 생성자 (MemberManager의 배열 생성을 위해 필수)
    Member() { name = ""; point = 0; }
    
    // 신규 회원 생성자: 이름 받아서 포인트 100으로 초기화!
    Member(string name) {
        this->name = name;
        this->point = 100;
    }
    
    // 정보 출력 함수
    void show() {
        cout << "[" << name << ", " << point << "]" << endl;
    }
    
    // += 연산자 오버로딩 (멤버 함수)
    Member& operator+=(int p) {
        point += p; // 포인트 증가
        return *this; // 업그레이드된 원본 반환
    }
};

// 2. 회원들을 관리하는 MemberManager 클래스
class MemberManager {
    Member mem[100]; // 최대 100명까지 저장하는 회원 배열
    int count;       // 현재 저장된 회원 수
public:
    MemberManager() { count = 0; } // 초기 회원 수는 0명
    
    // << 연산자 오버로딩 (신규 회원 저장)
    MemberManager& operator<<(Member m) {
        if (count < 100) {
            mem[count] = m; // 배열에 새 회원 객체 복사해서 넣기
            count++;        // 회원 수 1 증가
        }
        return *this; 
    }
    
    // [] 연산자 오버로딩 (참조 리턴!)
    Member& operator[](int index) {
        return mem[index]; // 배열에 있는 '원본 객체'를 연결해 줌!
    }
};

int main() {
    MemberManager man;
    for (int i = 0; i < 3; i++) {
        cout << "신규 회원 이름>> ";
        string name;
        cin >> name; // 고객 이름 입력
        man << Member(name); // << 연산자로 신규 회원 저장. 포인트는 100으로 초기화
    }

    for (int i = 0; i < 3; i++) {
        man[i].show(); // 처음 3명의 회원 정보 출력
    }
    
    man[2] += 500; // 3번째 회원의 포인트 500 점 증가
    Member& c = man[1]; // 회원 c는 2번째 저장된 회원(Member) 객체
    c += 200; // 회원 c의 포인트 200점 증가
    for (int i = 0; i < 3; i++) {
        man[i].show(); // 처음 3명의 회원 정보 출력
    }
}


