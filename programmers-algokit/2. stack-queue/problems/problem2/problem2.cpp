#include <string>
#include <vector>
#include <deque>

using namespace std;

int calcLeftDays(int number, int divisor) {
    if (number % divisor == 0) {
        return number / divisor;
    }
    return (number / divisor) + 1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> leftDays;
    
    for (int i = 0; i < progresses.size(); i++) {
        leftDays.push_back(calcLeftDays(100 - progresses.at(i), speeds.at(i)));
    }
    
    int present = leftDays.front();
    int count = 0;
    while (!leftDays.empty()) {
        if (leftDays.front() <= present) {
            leftDays.pop_front();
            count ++;
        } else {
            answer.push_back(count);
            present = leftDays.front();
            count = 0;
        }
    }
    answer.push_back(count);
    
    return answer;
}