#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> votes;  // key: 이름, value: 득표수
    
    while (true) {
        cout << "이름 3개 (종료시 '그만') >> ";
        
        bool stop = false;
        
        for (int i = 0; i < 3; i++) {
            string name;
            cin >> name;
            
            if (name == "그만") {
                stop = true;
                break;
            }
            
            votes[name]++;  // 해당 이름의 득표수 1 증가
                            // map에 없는 이름이면 자동으로 0으로 생성 후 +1
        }
        
        if (stop)
            break;  // while 루프 탈출
    }
    
    // 모든 후보 득표수 출력
    map<string, int>::iterator it;
    for (it = votes.begin(); it != votes.end(); it++) {
        cout << it->first << ":" << it->second << ", ";
    }
    cout << endl;
    
    // 최다 득표자 찾기
    string Winner;
    int maxVote = 0;
    for (it = votes.begin(); it != votes.end(); it++) {
        if (it->second > maxVote) {
            maxVote = it->second;
            Winner = it->first;  // 더 많은 득표수면 Winner 업데이트
        }
    }
    
    cout << Winner << "님이 회장으로 선출되었습니다." << endl;
}





// -> 1번째 코드 변형

// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;

// int main() {
//     map<string, int> votes;  // key: 이름, value: 득표수
    

//     bool stop = false;

//     while (!stop) {
//         cout << "이름 3개 (종료시 '그만') >> ";
        
//         for (int i = 0; i < 3; i++) {
//             string name;
//             cin >> name;
            
//             if (name == "그만") {
//                 stop = true;
//                 break;
//             }
//             votes[name]++;  // 해당 이름의 득표수 1 증가
//                             // map에 없는 이름이면 자동으로 0으로 생성 후 +1
//         }
//     }
    
//     // 모든 후보 득표수, 최다 득표자 출력
//     string Winner;
//     int maxVote = 0;
//     map<string, int>::iterator it;
//     for (it = votes.begin(); it != votes.end(); it++) {
//         cout << it->first << ":" << it->second << ", ";

//         if (it->second > maxVote) {
//             maxVote = it->second;
//             Winner = it->first;  // 더 많은 득표수면 Winner 업데이트
//         }
//     }
//     cout << endl;
    
//     cout << Winner << "님이 회장으로 선출되었습니다." << endl;
// }