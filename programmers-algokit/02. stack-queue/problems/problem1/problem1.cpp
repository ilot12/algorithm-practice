#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int prev;
    int present;
    answer.push_back(arr.at(0));
    
    for (int i = 1; i < arr.size(); i++) {
        prev = arr.at(i - 1);
        present = arr.at(i);
        if (present == prev) {
            continue;
        }
        answer.push_back(present);
        
    }

    return answer;
}