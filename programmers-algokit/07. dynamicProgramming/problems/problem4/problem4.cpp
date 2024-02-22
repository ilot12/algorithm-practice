#include <vector>
#include <string>
#include <iostream>

using namespace std;

int numberCount;
int operationCount;
vector<int> numberVec;
vector<int> isOperationPlus;
vector<vector<vector<int>>> partialMinMax;
vector<vector<vector<int>>> isMade;

void processArr(vector<string> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i % 2 == 0) {
            numberVec.push_back(stoi(arr.at(i)));
        }
        else {
            isOperationPlus.push_back(arr.at(i) == "+");
        }
    }
}

void init(vector<string> arr) {
    processArr(arr);
    numberCount = (arr.size() + 1) / 2;
    operationCount = arr.size() / 2;
    partialMinMax.resize(2, vector<vector<int>>(numberCount, vector<int>(numberCount)));
    isMade.resize(2, vector<vector<int>>(numberCount, vector<int>(numberCount)));

    for (int i = 0; i < numberCount; ++i) {
        partialMinMax[0][i][i] = partialMinMax[1][i][i] = numberVec.at(i);
        isMade.at(0).at(i).at(i) = true;
        isMade.at(1).at(i).at(i) = true;
    }
}

int calcPartialMinMax(bool isMax, int start, int end) {
    if (start == end) {
        return numberVec.at(start);
    }
    if (isMade.at(isMax).at(start).at(end)) {
        return partialMinMax[isMax][start][end];
    }
    else {
        if (isMax) {
            int partialMax = -1000000;
            for (int operation = start; operation < end; ++operation) {
                if (isOperationPlus.at(operation)) {
                    partialMax = max(partialMax,
                        calcPartialMinMax(1, start, operation) +
                        calcPartialMinMax(1, operation + 1, end));
                }
                else {
                    partialMax = max(partialMax,
                        calcPartialMinMax(1, start, operation) -
                        calcPartialMinMax(0, operation + 1, end));
                }
            }
            isMade.at(isMax).at(start).at(end) = true;
            partialMinMax.at(isMax).at(start).at(end) = partialMax;
            return partialMax;
        }
        if (!isMax) {
            int partialMin = 1000000;
            for (int operation = start; operation < end; ++operation) {
                if (isOperationPlus.at(operation)) {
                    partialMin = min(partialMin,
                        calcPartialMinMax(0, start, operation) +
                        calcPartialMinMax(0, operation + 1, end));
                }
                else {
                    partialMin = min(partialMin,
                        calcPartialMinMax(0, start, operation) -
                        calcPartialMinMax(1, operation + 1, end));
                }
            }
            isMade.at(isMax).at(start).at(end) = true;
            partialMinMax.at(isMax).at(start).at(end) = partialMin;
            return partialMin;
        }
    }
}


int solution(vector<string> arr)
{
    int answer = -1;
    init(arr);

    // cout << calcPartialMinMax(1, 0, numberCount - 1) << "\n";
    // for (int i = 0; i < numberCount; ++i) {
    //     for (int j = i + 1; j < numberCount; ++j) {
    //         cout << "Max(" << i << ", " << j << "): ";
    //         cout << calcPartialMinMax(1, i, j) << "\n";
    //     }
    // }
    
    
    
    return calcPartialMinMax(1, 0, numberCount - 1);
}