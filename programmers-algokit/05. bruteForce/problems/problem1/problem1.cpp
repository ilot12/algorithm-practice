#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int biggerMax = 0;
    int smallerMax = 0;

    for (vector<vector<int>>::iterator it = sizes.begin(); it != sizes.end(); ++it) {
        int bigger = (*it).at(0);
        int smaller = (*it).at(1);
        
        if (smaller > bigger) {
            swap(bigger, smaller);
        }
        
        if (biggerMax < bigger) {
            biggerMax = bigger;
        }
        
        if (smallerMax < smaller) {
            smallerMax = smaller;
        }
    }

    answer = biggerMax * smallerMax;

    return answer;
}