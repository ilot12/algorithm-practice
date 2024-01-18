//	사용된 숫자의 개수가 아니라 사용된 사칙연산의 개수로 잘못읽음~~~~ ㅋㅋㅋㅋ

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//  이미 만든 수는 만들었던 횟수가 더 적은걸로 해야하니(중복하면 안되니) map
//  key는 만든(만들) 수, value는 만드는데 사용했던 사칙연산 횟수
//  만들었나 만들지 못했나를 위해 set으로 하지 않은 이유는 답을 출력하기 위해
map<int, int> numberMade;

//  사칙 연산을 몇번 사용해서 만들 수 있는지에 대한 그룹.
//  operationCountGroup.at(0)에는 0번에 만들 수 있는 수가 
//  즉 n이 5라면 5, 55, 555, 5555가 들어있음
vector<vector<int>> operationCountGroup(10);

void printVector(vector<int> myVec) {
    for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << "\n";
}

void printSet(set<int> mySet) {
    for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << "\n";
}

void init(int N) {
    int value = N;

    vector<int> values;

    while (value <= 32000) {
        values.push_back(value);
        numberMade[value] = 0;
        value = value * 10 + N;
    }
    operationCountGroup.at(0) = values;
}

set<int> operateTwoGroup(vector<int> group1, vector<int> group2) {
    set<int> resultGroup;
    for (vector<int>::iterator it1 = group1.begin(); it1 != group1.end(); ++it1) {
        for (vector<int>::iterator it2 = group2.begin(); it2 != group2.end(); ++it2) {
            int num1 = *it1;
            int num2 = *it2;
            resultGroup.insert(num1 + num2);
            resultGroup.insert(num1 - num2);
            resultGroup.insert(num1 * num2);
            resultGroup.insert(num1 / num2);
        }
    }
    return resultGroup;
}

set<int> makeOperationCountGroup(int n) {
    set<int> countNGroup;
    vector<int> group1;
    vector<int> group2;

    //  사칙 연산 1번이면 0번그룹과 0번그룹으로 연산.
    //  사칙 연산 2번이면 0번그룹과 1번그룹으로 연산
    //  사칙연산 3번이면 0번그룹과 2번그룹 / 1번그룹과 1번그룹
    for (int i = 0; i <= (n - 1) / 2; ++i) {
        group1 = operationCountGroup.at(i);
        group2 = operationCountGroup.at(n - 1 - i);
        set<int> operatedTwoGroup = operateTwoGroup(group1, group2);
        for (set<int>::iterator it = operatedTwoGroup.begin(); it != operatedTwoGroup.end(); ++it) {
            if ((*it) > 0 && (*it) <= 32000) {
                countNGroup.insert(*it);
            }
        }
    }
    return countNGroup;
}

void fillNumberMade(int n, set<int> countNGroup) {
    vector<int> values;
    for (set<int>::iterator it = countNGroup.begin(); it != countNGroup.end(); ++it) {
        if (numberMade.find(*it) == numberMade.end()) {
            values.push_back(*(it));
            numberMade[*(it)] = n;
        }
    }
    operationCountGroup.at(n) = values;
    return;
}

int solution(int N, int number) {
    int answer = 0;

    init(N);

    for (int i = 1; i < 9; ++i) {
        fillNumberMade(i, makeOperationCountGroup(i));
    }

    if (numberMade.find(number) == numberMade.end()) {
        return -1;
    }
    else {
        return numberMade[number];
    }

    return answer;
}

int main(int argc, char** argv)
{
    cout << solution(5, 12);

    return 0;
}