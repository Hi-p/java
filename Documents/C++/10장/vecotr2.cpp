#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> scores;

    while (true) {
        double value = 0.0;
        cout << "성적을 입력하시오(종료는 -1): ";
        cin >> value;
        
        if (value == -1) {
            break;
        }
        scores.push_back(value);
    }

    double highest = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    cout << "최고 성적은 " << highest << "입니다" << endl;
}