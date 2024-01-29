#include <string>
#include <iostream>
#include <deque>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    deque<int> stk;

    for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) == '(') {
            stk.push_back(1);
        }
        if (s.at(i) == ')') {
            if (stk.empty()) {
                return false;
            }
            stk.pop_back();
        }
    }

    if (stk.empty()) {
        return true;
    }

    return false;
}