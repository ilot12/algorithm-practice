#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int boardSize;
vector<vector<int>> visited;

void dfs(int i, int j, vector<pair<int, int>> &coords) {
    coords.push_back({ i, j });
    if (i > 0) {
        if (!visited.at(i - 1).at(j)) {
            visited.at(i - 1).at(j) = true;
            dfs(i - 1, j, coords);
        }
    }
    if (i < boardSize - 1) {
        if (!visited.at(i + 1).at(j)) {
            visited.at(i + 1).at(j) = true;
            dfs(i + 1, j, coords);
        }
    }
    if (j > 0) {
        if (!visited.at(i).at(j - 1)) {
            visited.at(i).at(j - 1) = true;
            dfs(i, j - 1, coords);
        }
    }
    if (j < boardSize - 1) {
        if (!visited.at(i).at(j + 1)) {
            visited.at(i).at(j + 1) = true;
            dfs(i, j + 1, coords);
        }
    }
    return;
}

vector<vector<pair<int, int>>> boardSearchStart(bool isGameBoard, vector<vector<int>> board) {
    vector<vector<pair<int, int>>> blocks;

    visited.clear();
    visited.insert(visited.end(), board.begin(), board.end());
    if (!isGameBoard) {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (visited.at(i).at(j) == 1) {
                    visited.at(i).at(j) = 0;
                }
                else {
                    visited.at(i).at(j) = 1;
                }
            }
        }
    }
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (!visited.at(i).at(j)) {
                 vector<pair<int, int>> coords;
                 visited.at(i).at(j) = true;
                 dfs(i, j, coords);
                 blocks.push_back(coords);
            }
        }
    };
    return blocks;
}

void modifyCoords(vector<pair<int, int>> &coords) {
    int firstminCoord = 100;
    int secondminCoord = 100;
    for (pair<int, int> coord : coords) {
        firstminCoord = min(firstminCoord, coord.first);
        secondminCoord = min(secondminCoord, coord.second);
    }
    for (pair<int, int> &coord : coords) {
        coord.first -= firstminCoord;
        coord.second -= secondminCoord;
    }
    sort(coords.begin(), coords.end());
    return;
}

void turnBlock(vector<pair<int, int>> &block) {
    for (pair<int, int> &coord : block) {
        int second = coord.second;
        coord.second = coord.first;
        coord.first = 6 - second;
    }
    return;
}

string processOneBlock(vector<pair<int, int>> block) {
    vector<vector<pair<int, int>>> blockTypes;
    modifyCoords(block);
    blockTypes.push_back(block);
    for (int i = 0; i < 3; i++) {
        turnBlock(block);
        modifyCoords(block);
        blockTypes.push_back(block);
    }
    sort(blockTypes.begin(), blockTypes.end());
    string processedString = "";
    for (pair<int, int> coord : blockTypes.at(0)) {
        processedString += to_string(coord.first);
        processedString += to_string(coord.second);
    }
    return processedString;
}

vector<string> processBlocks(vector<vector<pair<int, int>>> blocks) {
    vector<string> processedBlocks;
    for (vector<pair<int, int>> block : blocks) {
        processedBlocks.push_back(processOneBlock(block));
    }
    return processedBlocks;
}

int countMatches(vector<string> processed_board_blocks, vector<string> processed_table_blocks) {
    int answer = 0;
    sort(processed_board_blocks.begin(), processed_board_blocks.end());
    sort(processed_table_blocks.begin(), processed_table_blocks.end());
    
    priority_queue<string> PQ_PBB(processed_board_blocks.begin(), processed_board_blocks.end());
    priority_queue<string> PQ_PTB(processed_table_blocks.begin(), processed_table_blocks.end());
    
    while (!PQ_PBB.empty()) {
        string PBB_TOP = PQ_PBB.top();
        PQ_PBB.pop();
        
        while (!PQ_PTB.empty()){
            if (PBB_TOP < PQ_PTB.top()){
                PQ_PTB.pop();
            } else {
                if (PBB_TOP == PQ_PTB.top()) {
                    PQ_PTB.pop();
                    answer += PBB_TOP.length() / 2;
                }
                break;
            }
        }
    }
    return answer;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;

    boardSize = game_board.size();
    vector<vector<pair<int, int>>> board_blocks = boardSearchStart(true, game_board);
    vector<vector<pair<int, int>>> table_blocks = boardSearchStart(false, table);
	
//     for (vector<pair<int, int>> block : board_blocks) {
//         cout << "보드 블럭 나간다!!: ";
//         for (pair<int, int> coord : block) {
//             cout << "(" << coord.first << ", " << coord.second << ")";
//         }
//         cout << "\n";
//     }
	
//     for (vector<pair<int, int>> block : table_blocks) {
//         cout << "테이블 블럭 나간다!!: ";
//         for (pair<int, int> coord : block) {
//             cout << "(" << coord.first << ", " << coord.second << ")";
//         }
//         cout << "\n";
//     }

    vector<string> processed_board_blocks = processBlocks(board_blocks);
    vector<string> processed_table_blocks = processBlocks(table_blocks);
    
//     for (string block : processed_board_blocks) {
//         cout << "정리된 보드 블럭 나간다!!: ";
//         cout << block;
//         cout << "\n";
//     }
	
//     for (string block : processed_table_blocks) {
//         cout << "정리된 테이블 블럭 나간다!!: ";
//         cout << block;
//         cout << "\n";
//     }
    
    return countMatches(processed_board_blocks, processed_table_blocks);
}