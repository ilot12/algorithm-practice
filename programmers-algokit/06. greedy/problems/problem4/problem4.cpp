#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    deque<int> peopleDeque(people.begin(), people.end());
    sort (peopleDeque.begin(), peopleDeque.end(), [](int a, int b) -> bool{
       return a > b; 
    });
    
    while (!peopleDeque.empty()) {
        if (peopleDeque.size() == 1) {
            return answer + 1;
        }
        int left = limit - peopleDeque.front();
        peopleDeque.pop_front();
        if (peopleDeque.back() <= left) {
            peopleDeque.pop_back();
        }
        answer++;
    }
    
    return answer;
}