#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    set<int> pokeSet(nums.begin(), nums.end());

    int count = nums.size();
    if (pokeSet.size() < count / 2) {
        return pokeSet.size();
    }
    else {
        return count / 2;
    }


    return answer;
}