#include <vector>
#include <map>
#include <deque>

using namespace std;

int bfs(vector<vector<int> > maps) {
    int width = maps.at(0).size();
    int height = maps.size();
    vector<vector<bool>> visited(100, vector<bool>(100, false));
    vector<vector<int>> moveCount(100, vector<int>(100));
    deque < pair<int, int>> bfsQueue;

    visited.at(0).at(0) = true;
    moveCount.at(0).at(0) = 1;
    bfsQueue.push_back({ 0,0 });

    //  maps에 벽이면 0, 땅이면 1이 있으므로 1이 있으면 다음 수행.
    while (!bfsQueue.empty()) {
        pair<int, int> point = bfsQueue.front();
        bfsQueue.pop_front();

        int upDown = point.first;
        int leftRight = point.second;
        int presentMoveCount = moveCount.at(upDown).at(leftRight);

        if (upDown == height - 1 && leftRight == width - 1) {
            return presentMoveCount;
        }

        //  오른쪽
        if (leftRight != width - 1) {
            if (maps.at(upDown).at(leftRight + 1)) {
                if (!visited.at(upDown).at(leftRight + 1)) {
                    bfsQueue.push_back({ upDown, leftRight + 1 });
                    moveCount.at(upDown).at(leftRight + 1) = presentMoveCount + 1;
                    visited.at(upDown).at(leftRight + 1) = true;
                }
            }
        }

        //  아래
        if (upDown != height - 1) {
            if (maps.at(upDown + 1).at(leftRight)) {
                if (!visited.at(upDown + 1).at(leftRight)) {
                    bfsQueue.push_back({ upDown + 1, leftRight });
                    moveCount.at(upDown + 1).at(leftRight) = presentMoveCount + 1;
                    visited.at(upDown + 1).at(leftRight) = true;
                }
            }
        }

        //  위
        if (upDown != 0) {
            if (maps.at(upDown - 1).at(leftRight)) {
                if (!visited.at(upDown - 1).at(leftRight)) {
                    bfsQueue.push_back({ upDown - 1, leftRight });
                    moveCount.at(upDown - 1).at(leftRight) = presentMoveCount + 1;
                    visited.at(upDown - 1).at(leftRight) = true;
                }
            }
        }

        //  왼쪽
        if (leftRight != 0) {
            if (maps.at(upDown).at(leftRight - 1)) {
                if (!visited.at(upDown).at(leftRight - 1)) {
                    bfsQueue.push_back({ upDown, leftRight - 1 });
                    moveCount.at(upDown).at(leftRight - 1) = presentMoveCount + 1;
                    visited.at(upDown).at(leftRight - 1) = true;
                }
            }
        }

    }

    return -1;
}

//  maps.at(i).at(j)를 하면 아래로 i칸, 오른쪽으로 j칸 이동함.
int solution(vector<vector<int> > maps)
{
    return bfs(maps);
}

