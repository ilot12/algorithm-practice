#include <string>
#include <vector>

using namespace std;

int answerOf1(int n) {
    return (n % 5) + 1;
}

int answerOf2(int n) {
    if (n % 2 == 0) {
        return 2;
    }
    switch ((n - 1) / 2 % 4) {
    case 0:
        return 1;
    case 1:
        return 3;
    case 2:
        return 4;
    case 3:
        return 5;
    default:
        return 0;
    }
}

int answerOf3(int n) {
    n /= 2;
    switch (n % 5) {
    case 0:
        return 3;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 4;
    case 4:
        return 5;
    default:
        return 0;
    }
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> correctCount({ 0, 0, 0 });
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers.at(i) == answerOf1(i)) {
            ++correctCount.at(0);
        }
        if (answers.at(i) == answerOf2(i)) {
            ++correctCount.at(1);
        }
        if (answers.at(i) == answerOf3(i)) {
            ++correctCount.at(2);
        }
    }

    int max = correctCount.at(0);
    for (int i = 0; i < 3; i++) {
        if (max < correctCount.at(i)) {
            max = correctCount.at(i);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (correctCount.at(i) == max) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}