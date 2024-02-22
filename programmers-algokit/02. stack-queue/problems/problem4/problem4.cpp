#include <iostream>
#include <string>
#include <vector>

using namespace std;

int oneCycle (vector<int> &priorities, int i, int targetValue, int &targetPosition, int targetCount) {
    int countI = 0;
    int lastPositionI = 0;
    for (int j = 0; j < priorities.size(); ++j) {
        if (priorities.at(j) == i) {
            ++countI;
            lastPositionI = j;
        }
    }
    if (countI == 0) {
        return 0;
    }
    
    vector<int> nextVector(priorities.begin() + lastPositionI + 1, priorities.end());
    for (int j = 0; j < lastPositionI; ++j) {
        if (priorities.at(j) != i) {
            nextVector.push_back(priorities.at(j));
            if (priorities.at(j) == targetValue) {
                --targetPosition;
            }
        }
    }
    if (targetPosition < 0) {
        targetPosition += targetCount;
    }
    priorities = nextVector;
    return countI;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    int targetValue = priorities.at(location);
    int targetPosition = 0;
    int targetCount = 0;
    for (int i = 0; i < priorities.size(); ++i) {
        if (priorities.at(i) == targetValue) {
            ++targetCount;
            if (i < location) {
                ++targetPosition;
            }
        }
    }
    
    for (int i = 9; i > 0; --i) {
        if (i == targetValue) {
            break;
        }
        answer += oneCycle(priorities, i, targetValue, targetPosition, targetCount);
    }
    
    answer += targetPosition;
    
    return answer;
}