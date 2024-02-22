#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//  벽의 어떤 사이드냐에 따라 타입을 나누려 함.
//  상단과 하단벽이면 좌우로 이동 가능
//  좌측과 우측 벽이라면 상하로 이동 가능.

//  코너가 아니면서 겹치는 곳은 아래와 같음.
//  상단 + 좌측 = ┘
//  상단 + 우측 = └
//  하단 + 좌측 = ┐
//  하단 + 우측 = ┌
//  코너면서 겹치는 곳은 반대로 이동가능.

//  isCorner
vector<vector<bool>> isCorner(60, vector<bool>(60));

//  types.at(x).at(y)에는 (x,y)의 타입이 들어있을 예정.
//  타입으로는 상단 : 1, 하단 : 2, 좌측 : 3, 우측 : 4
//  상 + 좌 = 5, 상 + 우 = 6, 하 + 좌 = 7, 하 + 우 = 8
//  코너라면 반대 즉 13 - type을 해주면 된다.
vector<vector<int>> types(60, vector<int>(60));

void makeTypes(int x, int y, int type) {
    if (types.at(x).at(y) == 0) {
        types.at(x).at(y) = type;
    }
    else {
        types.at(x).at(y) = types.at(x).at(y) + type + min(types.at(x).at(y), type);
        if (isCorner.at(x).at(y)) {
            types.at(x).at(y) = 13 - types.at(x).at(y);
        }
    }
}

void bulidTypes(vector<int> oneRectangle) {
    int left = oneRectangle.at(0);
    int down = oneRectangle.at(1);
    int right = oneRectangle.at(2);
    int up = oneRectangle.at(3);

    isCorner.at(left).at(down) = true;
    isCorner.at(left).at(up) = true;
    isCorner.at(right).at(down) = true;
    isCorner.at(right).at(up) = true;

    for (int i = left; i <= right; ++i) {
        makeTypes(i, up, 1);
        makeTypes(i, down, 2);
    }
    for (int i = down; i <= up; ++i) {
        makeTypes(left, i, 3);
        makeTypes(right, i, 4);
    }
}

vector<int> answers;
vector<vector<bool>> visited(60, vector<bool>(60, false));

void dfs(int x, int y, int itemX, int itemY, int& moveCount) {
    moveCount += 1;
    if (x == itemX && y == itemY) {
        answers.push_back(moveCount);
        visited.at(x).at(y) = false;
        moveCount = 0;
        return;
    }
    switch (types.at(x).at(y)) {
    case 1:
    case 2:
        if (!visited.at(x + 1).at(y)) {
            visited.at(x + 1).at(y) = true;
            dfs(x + 1, y, itemX, itemY, moveCount);
        }
        if (!visited.at(x - 1).at(y)) {
            visited.at(x - 1).at(y) = true;
            dfs(x - 1, y, itemX, itemY, moveCount);
        }
        return;
    case 3:
    case 4:
        if (!visited.at(x).at(y + 1)) {
            visited.at(x).at(y + 1) = true;
            dfs(x, y + 1, itemX, itemY, moveCount);
        }
        if (!visited.at(x).at(y - 1)) {
            visited.at(x).at(y - 1) = true;
            dfs(x, y - 1, itemX, itemY, moveCount);
        }
        return;
    case 5:
        if (!visited.at(x - 1).at(y)) {
            visited.at(x - 1).at(y) = true;
            dfs(x - 1, y, itemX, itemY, moveCount);
        }
        if (!visited.at(x).at(y + 1)) {
            visited.at(x).at(y + 1) = true;
            dfs(x, y + 1, itemX, itemY, moveCount);
        }
        return;
    case 6:
        if (!visited.at(x + 1).at(y)) {
            visited.at(x + 1).at(y) = true;
            dfs(x + 1, y, itemX, itemY, moveCount);
        }
        if (!visited.at(x).at(y + 1)) {
            visited.at(x).at(y + 1) = true;
            dfs(x, y + 1, itemX, itemY, moveCount);
        }
        return;
    case 7:
        if (!visited.at(x - 1).at(y)) {
            visited.at(x - 1).at(y) = true;
            dfs(x - 1, y, itemX, itemY, moveCount);
        }
        if (!visited.at(x).at(y - 1)) {
            visited.at(x).at(y - 1) = true;
            dfs(x, y - 1, itemX, itemY, moveCount);
        }
        return;
    case 8:
        if (!visited.at(x + 1).at(y)) {
            visited.at(x + 1).at(y) = true;
            dfs(x + 1, y, itemX, itemY, moveCount);
        }
        if (!visited.at(x).at(y - 1)) {
            visited.at(x).at(y - 1) = true;
            dfs(x, y - 1, itemX, itemY, moveCount);
        }
        return;
    }
    moveCount -= 1;
    return;
}

int dfsStart(int characterX, int characterY, int itemX, int itemY) {
    int moveCount = -1;
    visited.at(characterX).at(characterY) = true;
    dfs(characterX, characterY, itemX, itemY, moveCount);
    return min(answers.at(0), answers.at(1));
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    for (vector<int> oneRectangle : rectangle) {
        bulidTypes(oneRectangle);
    }

    return dfsStart(characterX, characterY, itemX, itemY);

    return answer;
}