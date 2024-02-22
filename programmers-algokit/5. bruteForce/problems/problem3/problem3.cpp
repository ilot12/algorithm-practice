#include <string>
#include <vector>
#include <set>

using namespace std;

vector<bool> isPrime(1000001, true);

void makePrimes() {
    isPrime.at(0) = false;
    isPrime.at(1) = false;
    for (int i = 2; i <= 1000; ++i) {
        if (!isPrime.at(i)) {
            continue;
        }
        for (int j = i + i; j <= 1000000; j += i) {
            isPrime.at(j) = false;
        }
    }
}

vector<bool> visited;
set<int> numberSet;
string number;
string numberString;
int length;

void dfs(int position) {
    number += numberString.at(position);
    numberSet.insert(stoi(number));
    for (int i = 0; i < length; ++i) {
        if (visited[i]) {
            continue;
        }
        else {
            visited[i] = true;
            dfs(i);
            visited[i] = false;
        }
    }
    number = number.substr(0, number.length() - 1);
    return;
}

void startDfs(string numbers) {
    length = numbers.length();
    visited = vector<bool>(length, false);
    number = "";
    for (int i = 0; i < length; ++i) {
        visited[i] = true;
        dfs(i);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    makePrimes();
    numberString = numbers;
    startDfs(numbers);
    for (int num : numberSet) {
        if (num > 1000000) {
            continue;
        }
        if (isPrime[num]) {
            answer++;
        }
    }

    return answer;
}