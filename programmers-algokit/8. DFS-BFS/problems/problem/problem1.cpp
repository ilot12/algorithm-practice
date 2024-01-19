#include <string>
#include <vector>

using namespace std;

vector<int> nums;
int counts;

void dfs(int depth, int value, int endDepth, int target) {
    if (depth == endDepth - 1) {
        if (value == target) {
            ++counts;
            return;
        }
        return;
    }

    dfs(depth + 1, value + nums.at(depth + 1), endDepth, target);
    dfs(depth + 1, value - nums.at(depth + 1), endDepth, target);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    int numberSize = numbers.size();

    nums = numbers;

    int value = 0;
    counts = 0;
    dfs(0, numbers.at(0), numberSize, target);
    dfs(0, -numbers.at(0), numberSize, target);
    
    return counts;
}
