#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;

    //  이동으로 인한 조작 횟수(왼쪽 오른쪽) 세기

    deque<int> right;
    deque<int> left;

    int count = -1;

    //  right 세는 사이클
    for (int i = 0; i < name.length(); ++i) {
        ++count;
        if (name.at(i) == 'A') {
            continue;
        }
        if (i == name.length() - 1) {
            right.push_back(count);
            count = 0;
            break;
        }
        if (name.at(i + 1) == 'A') {
            right.push_back(count);
        }
    }

    count = 0;
    //left 세는 사이클
    for (int i = name.length() - 1; i >= 0; --i) {
        ++count;
        if (name.at(i) == 'A') {
            continue;
        }
        if (i == 0) {
            left.push_front(count);
            count = 0;
            break;
        }
        if (name.at(i - 1) == 'A') {
            left.push_front(count);
        }
    }

    int moveCount = 1000000000;
    if (right.empty()) {
        moveCount = 0;
    }
    if (!right.empty()) {

        moveCount = left.front();
        left.pop_front();

        while (!left.empty()) {
            int rightMove = right.front();
            int leftMove = left.front();
            right.pop_front();
            left.pop_front();

            moveCount = min(moveCount, rightMove + leftMove + min(rightMove, leftMove));
        }
        moveCount = min(moveCount, right.front());
    }

    //  알파벳 변환으로 생기는 조작 횟수(위 아래) 세기
    for (int i = 0; i < name.length(); ++i) {
        int count = name.at(i) - 'A';
        if (count > 13) {
            count = 26 - count;
        }
        answer += count;
    }

    answer += moveCount;

    return answer;
}