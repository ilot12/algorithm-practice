#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int>> dungeonsVec;
int maxCount;
int counts;

void dfs(int leftFatigue,int dungeonNumber) {
    bool runDungeon = false;
    if (leftFatigue >= dungeonsVec.at(dungeonNumber).at(0)) {
        runDungeon = true;
        counts++;
        maxCount = max(counts, maxCount);
        leftFatigue -= dungeonsVec.at(dungeonNumber).at(1);
    }
        for (int i = 0; i < dungeonsVec.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            else {
                visited[i] = true;
                dfs(leftFatigue, i);
                visited[i] = false;
            }
        }
    
    if (runDungeon) {
        leftFatigue += dungeonsVec.at(dungeonNumber).at(1);
        counts--;
    }
}

void dfsStart(int fatigue, vector<vector<int>> dungeons) {
    visited = vector<bool> (dungeons.size(), false);
    maxCount = 0;
    for (int i = 0; i < dungeons.size(); ++i) {
        counts = 0;
        visited[i] = true;
        dfs(fatigue, i);
        visited[i] = false;
    }
    
    
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeonsVec = dungeons;
    dfsStart(k, dungeons);
    
    return maxCount;
}