#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    bool lostTable[31];
    bool reserveTable[31];    
    for (int i = 0; i < 31; i++) {
        lostTable[i] = reserveTable[i] = false;
    }
    
    for (vector<int>::iterator it = lost.begin(); it != lost.end(); ++it) {
        lostTable[*it - 1] = true;
    }
    for (vector<int>::iterator it = reserve.begin(); it != reserve.end(); ++it) {
        reserveTable[*it - 1] = true;
    }
    for (int i = 0; i < 30; i++) {
        if (lostTable[i] && reserveTable[i]) {
            lostTable[i] = false;
            reserveTable[i] = false;
            ++answer;
        }
    }
    for (int i = 0; i < 30; i++) {
        if (lostTable[i]) {
            if (i != 0){
                if (reserveTable[i - 1]) {
                    reserveTable[i - 1] = false;
                    ++answer;
                    continue;
                }
            }
            if (i != 29){
                if (reserveTable[i + 1]) {
                    reserveTable[i + 1] = false;
                    ++answer;
                    continue;
                }
            }
        }
    }
    
    return answer;
}