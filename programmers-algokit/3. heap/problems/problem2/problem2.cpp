#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    vector<int> endTimes;
    priority_queue<int, vector<int>, greater<int>> requestedTasks;

    sort(jobs.begin(), jobs.end());

    int presentTime = 0;
    deque<vector<int>> jobsDeque(jobs.begin(), jobs.end());
    while (!jobsDeque.empty()) {
        while (jobsDeque.at(0).at(0) <= presentTime) {
            vector<int> task = jobsDeque.at(0);
            requestedTasks.push(task.at(1));
            jobsDeque.pop_front();
            if (jobsDeque.empty()) {
                break;
            }
        }
        if (requestedTasks.empty()) {
            presentTime = jobsDeque.at(0).at(0);
        }
        else {
            presentTime += requestedTasks.top();
            requestedTasks.pop();
            endTimes.push_back(presentTime);
        }
    }

    while (!requestedTasks.empty()) {
        presentTime += requestedTasks.top();
        requestedTasks.pop();
        endTimes.push_back(presentTime);
    }

    int endTimeSum = 0;
    for (int num : endTimes) {
        endTimeSum += num;
    }

    int startTimeSum = 0;
    for (int i = 0; i < jobs.size(); ++i) {
        startTimeSum += jobs.at(i).at(0);
    }
    
    answer = (endTimeSum - startTimeSum) / jobs.size();

    return answer;
}