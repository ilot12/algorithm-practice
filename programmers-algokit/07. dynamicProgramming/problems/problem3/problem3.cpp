#include <string>
#include <vector>
#include <set>

#define DIVISOR 1000000007;

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    set<pair<int, int>> puddleSet;
    for (vector<vector<int>>::iterator it = puddles.begin(); it != puddles.end(); ++it) {
        puddleSet.insert(make_pair((*it)[0], (*it)[1]));
    }

    vector<vector<int>> lines;
    for (int i = 1; i <= n; ++i) {
        vector<int> line;
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) {
                line.push_back(1);
                continue;
            }
            if (puddleSet.find(make_pair(j, i)) != puddleSet.end()) {
                line.push_back(0);
                continue;
            }
            int fromLeft = 0;
            int fromUp = 0;
            if (i == 1) {
                fromUp = 0;
            }
            else {
                fromUp = lines.at(i - 1 - 1).at(j - 1);
            }
            if (j == 1) {
                fromLeft = 0;
            }
            else {
                fromLeft = line.at(j - 1 - 1);
            }
            int sum = (fromLeft + fromUp) % DIVISOR;
            line.push_back(sum);
        }
        lines.push_back(line);
    }
    answer = lines.at(n - 1).at(m - 1);

    return answer;
}