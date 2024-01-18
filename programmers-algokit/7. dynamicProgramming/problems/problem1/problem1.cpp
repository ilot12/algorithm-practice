#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

//  이미 만든 수는 만들었던 횟수가 더 적은걸로 해야하니(중복하면 안되니) map
//  key는 만든(만들) 수, value는 만드는데 사용했던 수
//  만들었나 만들지 못했나를 위해 set으로 하지 않은 이유는 답을 출력하기 위해
map<int, int> numberMade;

//  수를 몇번 사용해서 만들 수 있는지에 대한 그룹.
//  operationCountGroup.at(1)에는 1개로 만들 수 있는 수가 들어있음.
//  n이 5일 때 at(1)에는 5가, n이 2일때는 5 +,-,*,/ 5와 55가 들어있음.
vector<vector<int>> numberCountGroup(10);

//  55,555,5555와 같은 수가 들어있는 벡터
//  맨 앞에서 하나씩 꺼낼거여서 deque로 선언함.
//  2일 때는 22222까지 들어있음 주의.
deque<int> numberMadeByRepetition;

void init(int N) {
    int value = N;

    vector<int> values({ value });
    numberMade[value] = 1;
    numberCountGroup.at(1) = values;

    while (value <= 32000) {
        value = value * 10 + N;
        numberMadeByRepetition.push_back(value);
    }
}

set<int> operateTwoGroup(vector<int> group1, vector<int> group2) {
    set<int> resultGroup;
    for (vector<int>::iterator it1 = group1.begin(); it1 != group1.end(); ++it1) {
        for (vector<int>::iterator it2 = group2.begin(); it2 != group2.end(); ++it2) {
            int num1 = *it1;
            int num2 = *it2;
            resultGroup.insert(num1 + num2);
            resultGroup.insert(num1 - num2);
            resultGroup.insert(num2 - num1);
            resultGroup.insert(num1 * num2);
            resultGroup.insert(num1 / num2);
            resultGroup.insert(num2 / num1);
        }
    }
    return resultGroup;
}

set<int> makeNumberCountGroup(int n) {
    set<int> countNGroup;
    vector<int> group1;
    vector<int> group2;

    //  5가 2개 사용된 그룹이면 1개그룹과 1개그룹 연산 + repetition에서 한개
    //  5가 3개 사용된 그룹이면 1개 그룹과 2개그룹 연산 + repetition에서 한개
    //  5가 4개 사용된 그룹이면 1개/3개 와 2개/2개 그룹 연산 + repetition에서 한개
    for (int i = 1; i <= n / 2; ++i) {
        group1 = numberCountGroup.at(i);
        group2 = numberCountGroup.at(n - i);
        set<int> operatedTwoGroup = operateTwoGroup(group1, group2);
        for (set<int>::iterator it = operatedTwoGroup.begin(); it != operatedTwoGroup.end(); ++it) {
            if ((*it) > 0 && (*it) <= 32000) {
                countNGroup.insert(*it);
            }
        }
    }
    if (!numberMadeByRepetition.empty()) {
        countNGroup.insert(numberMadeByRepetition.front());
        numberMadeByRepetition.pop_front();
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
    numberCountGroup.at(n) = values;
    return;
}

int solution(int N, int number) {
    int answer = 0;

    init(N);

    for (int i = 2; i < 9; ++i) {
        fillNumberMade(i, makeNumberCountGroup(i));
    }

    if (numberMade.find(number) == numberMade.end()) {
        return -1;
    }
    else {
        return numberMade[number];
    }

    return answer;
}