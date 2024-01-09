#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> numberString;

    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        numberString.push_back(to_string(*it));
    }

    sort(numberString.begin(), numberString.end(), [](const string a, const string b) -> bool {
        return a + b > b + a;
    });

    for (vector<string>::iterator it = numberString.begin(); it != numberString.end(); ++it) {
        answer.append(*it);
    }

	//	미친반례 뭐야진짜 ㅡㅡ 0,0,0 넣었을 때 000이 아닌 0이 출력되야 한대.
    if (answer.at(0) == '0') {
        return "0";
    }

    return answer;
}