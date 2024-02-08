#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isOk(int mid, vector<int> citations) {
    if (mid == 0) {
        return true;
    }
    if (citations.size() < mid) {
        return false;
    }
    if (citations.at(citations.size() - mid) >= mid ) {
        return true;
    }
    return false;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int startIndex = 0;
    int endIndex = 10000;
    
    // 0   1   3   5   6
    // 5개 4개  3개 2개 1개
    
    // 2
    
    
    int midIndex;
    while (!(endIndex - startIndex == 1)) {
        midIndex = (startIndex + endIndex) / 2;
        if (isOk(midIndex, citations)) {
            startIndex = midIndex;
        } else {
            endIndex = midIndex;
        }
    }
    if (isOk(startIndex, citations)) {
        return startIndex;
    } else {
        return endIndex;
    }
}