#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answerOf1({1, 2, 3, 4, 5});
vector<int> answerOf2({2, 1, 2, 3, 2, 4, 2, 5});
vector<int> answerOf3({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});

//특정 패턴이 반복만되는 경우 그 아이디어를 수로 만드려 하지 말자.
//switch-case문 보다는 vector를 만들어서 myVec.at(i % myVec.size())를 해주면 됨.

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> correctCount({ 0, 0, 0 });
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers.at(i) == answerOf1.at(i % answerOf1.size())) {
            ++correctCount.at(0);
        }
        if (answers.at(i) == answerOf2.at(i % answerOf2.size())) {
            ++correctCount.at(1);
        }
        if (answers.at(i) == answerOf3.at(i % answerOf3.size())) {
            ++correctCount.at(2);
        }
    }

// 최대를 구하는 함수를 맨날 만들어 쓰지 말라. 라이브러리에 있네
    int max = *max_element(correctCount.begin(), correctCount.end());

    for (int i = 0; i < 3; i++) {
        if (correctCount.at(i) == max) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}