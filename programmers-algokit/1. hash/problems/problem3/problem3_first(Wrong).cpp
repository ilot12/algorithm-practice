/*
	단어들끼리 각각 비교하는 방법. log (O^2)이라 시간초과됨.
	단어들끼리 비교하는 것보다 단어를 자기길이 - 1 까지 각각 자르는게 더 빠름(충격)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//  str1이 긴거, str2가 짧은거
bool hasSamePart(string str1, string str2) {
    if (str1.substr(0, str2.length()) == str2) {
        return true;
    }
    return false;
}

bool existPrefix(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (hasSamePart(phone_book.at(i), phone_book.at(j))) {
                return false;
            }
        }
    }
    return true;
}

bool compare(string str1, string str2) {
    return str1.length() < str2.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), compare);


    return existPrefix(phone_book);
}


int main() {

    vector<string> phone_book({ "123","456","789" });
    cout << solution(phone_book);

	return 0;
}
