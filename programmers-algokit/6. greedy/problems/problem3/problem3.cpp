#include <string>
#include <vector>

using namespace std;

bool positionReachEnd = false;

void positionAdvance(string number, int& position) {
    while (number.at(position - 1) >= number.at(position)) {
        if (position >= number.length() - 1) {
            if (number.at(position - 1) > number.at(position)) {
                positionReachEnd = true;
            }
            return;
        }
        position++;
    }
    return;
}

void subtractString(string& number, int& position) {
    if (position == 1) {
        number = number.substr(1, number.length() - 1);
        return;
    }
    string left = number.substr(0, position - 1);
    string right = number.substr(position, number.length() - position);
    number = left + right;
    position--;
    return;
}

string solution(string number, int k) {
    int position = 1;
    for (int i = 0; i < k; ++i) {
        positionAdvance(number, position);
        if (positionReachEnd) {
            return number.substr(0, number.length() - (k - i));
        }
        subtractString(number, position);
    }
    return number;
}