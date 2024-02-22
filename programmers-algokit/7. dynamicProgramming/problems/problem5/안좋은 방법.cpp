#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int houseCount = money.size();
    //  한바퀴 이어진걸 하려고 두배로 늘렸음. 이제 한바퀴 도는 것도 +까지로 가능.
    vector<int> money2(money.begin(), money.end());
    money.insert(money.end(), money2.begin(), money2.end());
    
    map<pair<int, int>, int> maxMoney;
    for (int i = 0; i < houseCount; ++i) {
        int temp = maxMoney[{i, i}] = money.at(i);
        answer = max(answer, temp);
    }
    for (int i = 0; i < houseCount; ++i) {
        int temp = maxMoney[{i, i + 1}] = max(money.at(i), money.at(i + 1));
        answer = max(answer, temp);
    }
    // for (int i = 0; i < houseCount; ++i) {
    //     int temp = maxMoney[{i, i + 2}] = max(maxMoney[{i, i + 1}], money.at(i + 2) + maxMoney[{i, i}]);
    //     cout << "maxMoney(" << i << ", " << i + 2 << ") = " << temp << "\n";
    //     answer = max(answer, temp);
    // }
    // //  둘 차이가 최대 즉, 마지막인 경우는 끝에 걸 만나는걸 빼줘야 함.
    // // 그래서 max에서 두 번째 것에 maxMOney({i + 1}<<<<, ~~) 저기를 i + 1부터 해주어야 함.
    // for (int i = 0; i < houseCount; ++i) {
    //     int temp = maxMoney[{i, i + 3}] = max(maxMoney[{i, i + 2}], money.at(i + 3) + maxMoney[{i + 1, i + 1}]);
    //     cout << "maxMoney(" << i << ", " << i + 3 << ") = " << temp << "\n";
    //     answer = max(answer, temp);
    // }
    for (int j = 2; j < houseCount; ++j) {
        if (j != houseCount - 1) {
            for (int i = 0; i < houseCount; ++i) {
                int temp = maxMoney[{i, i + j}] = max(maxMoney[{i, i + j - 1}], money.at(i + j) + maxMoney[{i, i + j - 2}]);
                answer = max(answer, temp);
            }
        }
        if (j == houseCount - 1) {
            for (int i = 0; i < houseCount; ++i) {
                int temp = maxMoney[{i, i + j}] = max(maxMoney[{i, i + j - 1}], money.at(i + j) + maxMoney[{i + 1, i + j - 2}]);
                answer = max(answer, temp);
            }
        }
    }
    
    return answer;
}