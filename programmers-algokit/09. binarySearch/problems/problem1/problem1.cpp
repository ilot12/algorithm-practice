#include <vector>

using namespace std;

#define LONG_LONG_MAX_VALUE 9223372036854775807

bool thisNumberOK(int peopleCount, long long totalTime, vector<int> times) {
    long long count = 0;
    for (int inspectTime : times) {
        count += totalTime / inspectTime;
		//	여기가 실수 포인트. 6번이랑 9번이 여기서 실패나옴.
        if (count >= peopleCount) {
            return true;
        }
    }

    return false;
}

bool adjustInterval(long long& intervalBegin, long long& intervalEnd, int peopleCount, vector<int> times) {
    long long mid = (intervalEnd + intervalBegin) / 2;
    bool isMidOk = thisNumberOK(peopleCount, mid, times);

    if (intervalEnd - intervalBegin == 1) {
        return false;
    }

    if (!isMidOk) {
        intervalBegin = mid;
        return true;
    }

    if (isMidOk) {
        intervalEnd = mid;
        return true;
    }
}


long long binarySearch(int peopleCount, vector<int> times) {
    long long intervalBegin = 0;
    long long intervalEnd = LONG_LONG_MAX_VALUE;

    while (adjustInterval(intervalBegin, intervalEnd, peopleCount, times)) {
    }

    return intervalEnd;
}

long long solution(int n, vector<int> times) {
    return binarySearch(n, times);
}