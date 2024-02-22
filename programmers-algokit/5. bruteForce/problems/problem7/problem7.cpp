#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> dic;

vector<string> charVec({"A", "E", "I", "O", "U"});

string addChar(string str, int length) {
    if (length == 5) {
        return "";
    }
    for (int i = 0; i < 5; ++i) {
        str += charVec.at(i);
        dic.push_back(str);
        addChar(str, length + 1);
        str = str.substr(0, str.length() - 1);
    }
    return "";
}

void makeDic() {
    int length = 0;
    addChar("", length);
}

bool isWordOver(int midIndex, string word) {
    if (dic.at(midIndex) > word) {
        return true;
    }
    return false;
}

int findWord(string word) {
    int startIndex = 0;
    int endIndex = dic.size() - 1;
    int midIndex;
    while (endIndex - startIndex != 1) {
        midIndex = (startIndex + endIndex) / 2;
        if (isWordOver(midIndex, word)) {
            endIndex = midIndex;   
        }
        else {
            startIndex = midIndex;
        }
    }
    if (dic.at(endIndex) == word) {
        return endIndex + 1;
    }
    if (dic.at(startIndex) == word) {
        return startIndex + 1;
    }
}


int solution(string word) {
    int answer = 0;
    
    makeDic();
    return findWord(word);
}