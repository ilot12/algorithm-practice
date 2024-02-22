#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//  str1이 왼쪽거, str2가 오른쪽거
bool hasSamePart(string str1, string str2) {
    if (str1.length() > str2.length()) {
        return false;
    }
    if (str2.substr(0, str1.length()) == str1) {
        return true;
    }
    return false;
}

bool existPrefix(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size() - 1; ++i) {
        if (hasSamePart(phone_book.at(i), phone_book.at(i + 1))) {
            return false;
        }
    }
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    return existPrefix(phone_book);
}