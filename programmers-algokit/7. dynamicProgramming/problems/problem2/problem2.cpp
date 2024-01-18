#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> maxSum;

    maxSum.push_back(triangle.at(0));
    for (int i = 1; i < triangle.size(); ++i) {
        vector<int> presentLine = triangle.at(i);
        vector<int> previousSum = maxSum.at(i - 1);
        vector<int> sumLine;
        for (int j = 0; j < presentLine.size(); ++j) {
            if (j == 0) {
                sumLine.push_back(previousSum.at(0) + presentLine.at(0));
                continue;
            }
            if (j == presentLine.size() - 1) {
                sumLine.push_back(previousSum.at(j - 1) + presentLine.at(j));
                continue;
            }
            sumLine.push_back(max(previousSum.at(j - 1), previousSum.at(j)) + presentLine.at(j));
        }
        maxSum.push_back(sumLine);
    }

    vector<int> lastLine = *(maxSum.end() - 1);
    answer = *max_element(lastLine.begin(), lastLine.end());




    return answer;
}