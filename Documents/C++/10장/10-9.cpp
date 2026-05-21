#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, string> dic; // string형을 key로, string형을 value로 하는 map dic 선언
    dic["love"] = "사랑"; // key "love"에 value "사랑" 저장
    dic["apple"] = "사과"; // key "apple"에 value "사과" 저장
    dic["cherry"] = "체리"; // key "cherry"에 value "체리" 저장

    cout << "저장된 단어 개수 " << dic.size() << endl;

    string eng; // string형 변수 eng 선언
    while(true) {
        cout << "찾고 싶은 단어 >> ";
        getline(cin, eng);
        if (eng == "exit")
            break;

        if (dic.find(eng) == dic.end())
            cout << "없음" << endl;
        else
            cout << dic[eng] << endl;
    }
    cout << "종료합니다..." << endl;
}