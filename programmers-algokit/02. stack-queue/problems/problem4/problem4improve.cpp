#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue<int> pq(priorities.begin(), priorities.end());
    deque<pair<int, int>> propertiesLocation;

    for (int i = 0; i < priorities.size(); ++i) {
        propertiesLocation.push_back({ priorities.at(i), i });
    }

    int numberToPop = pq.top();
    while (!pq.empty()) {
        if (propertiesLocation.front().first == numberToPop) {
            ++answer;
            if (propertiesLocation.front().second == location) {
                break;
            }
            pq.pop();
            numberToPop = pq.top();
        }
        propertiesLocation.push_back(propertiesLocation.front());
        propertiesLocation.pop_front();
    }

    return answer;
}