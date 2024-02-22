#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr)
{
    deque<int> numberDeque;

    numberDeque.push_back(arr.at(0));
	
	//Stack은 앞에서부터 꺼내거나 iterator연산이 불가능하여 deque사용
	//앞에서부터 꺼낼 수 있는 queue를 사용하면 또 맨 뒤의 것을 확인하기 어려우니 곤란
    for (int i = 1; i < arr.size(); i++) {
        if (numberDeque.back() == arr.at(i)) {
            continue;
        }
        numberDeque.push_back(arr.at(i));
    }

    vector<int> answer(numberDeque.begin(), numberDeque.end());

    return answer;
}