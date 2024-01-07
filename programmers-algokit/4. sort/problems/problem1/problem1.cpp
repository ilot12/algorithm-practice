#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<vector<int>>::iterator it = commands.begin(); it != commands.end(); it++) {
        vector<int> presentArray(array.begin() + (*it).at(0) - 1, array.begin() + (*it).at(1));
        sort(presentArray.begin(), presentArray.end());
        answer.push_back(presentArray.at((*it).at(2) - 1));
    }

    return answer;
}