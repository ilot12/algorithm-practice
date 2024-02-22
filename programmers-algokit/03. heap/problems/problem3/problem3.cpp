#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> numbers;
    
    for (string operation: operations) {
        if (operation.at(0) == 'I') {
            numbers.push_back(stoi(operation.substr(2, operation.length() - 2)));
            sort(numbers.begin(), numbers.end());
        }
        if (!numbers.empty()){
            if (operation == "D 1") {
                numbers.pop_back();
            }
            if (operation == "D -1") {
                numbers.pop_front();
            }
        }
    }
    
    if (numbers.empty()) {
        numbers.push_back(0);
    }
    
    answer.push_back(numbers.back());
    answer.push_back(numbers.front());
    
    return answer;
}