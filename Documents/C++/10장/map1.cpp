#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, string> dic; // string형을 key로, string형을 value로 하는 map인 dic 선언
    dic["boy"] = "소년";
    dic["school"] = "학교";
    dic["office"] = "직장";
    dic["house"] = "집";
    dic["moring"] = "아침";
    dic["evening"] = "저녁";

    cout << "house의 의미는 " << dic["house"] << endl; // dic에서 "house"라는 key에 해당하는 value를 출력
    cout << "moring의 의미는 " << dic["moring"] << endl; // dic에서 "moring"라는 key에 해당하는 value를 출력
    cout << "unknown의 의미는 " << dic["unknown"] << endl; // dic에서 "unknown"라는 key에 해당하는 value를 출력, 존재하지 않는 key이므로 빈 문자열이 출력
}