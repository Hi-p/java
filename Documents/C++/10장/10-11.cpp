#include <iostream>
#include <string>
#include <map>
using namespace std;

void printmap(map<string, int> &m) {
    map<string, int>::iterator it; 
    for (it = m.begin(); it != m.end(); it++) {
    string menu = it->first; // map의 key값을 menu에 저장
    int price = it->second; // map의 value값을 price에 저장
    cout << menu << " : " << price << "원" << endl; 
    }
}

int main() {
    map<string, int> pricemap; // string형을 key로, int형을 value로 하는 map pricemap 선언
    pricemap["붕어빵"] = 2000;
    pricemap["잉어빵"] = 2500;
    pricemap["국화빵"] = 3000;
    printmap(pricemap); // pricemap의 원소들을 출력하는 함수 printmap 호출
    cout << endl;

    pricemap.erase("붕어빵"); // key "붕어빵"에 해당하는 원소 삭제
    printmap(pricemap);
}