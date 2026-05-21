#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> st; // string형을 저장하는 stack인 st 선언
    string sayings[3] = {"The grass is greener on the other side of the fence", "Even the greatest make mistakes", "To see is to believe"}; // string형 배열 sayings 선언 및 초기화, size 3
    for (int i = 0; i < 3; i++) {
        st.push(sayings[i]); // stack st에 sayings 배열의 요소들을 push
    }
    while (!st.empty()) {
        cout << st.top() << endl; // stack st의 top 요소를 출력
        st.pop(); // stack st의 top 요소를 pop
    }
}