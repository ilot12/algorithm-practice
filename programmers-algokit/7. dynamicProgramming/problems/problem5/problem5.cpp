#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    vector<int> M(money.size());
    vector<int> MStartBy1(money.size());
    M[0] = money.at(0);
    M[1] = max(money.at(0), money.at(1));
    
    MStartBy1[0] = 0;
    MStartBy1[1] = money.at(1);
    
    for (int i = 2; i < money.size(); ++i) {
        M[i] = max(M[i - 2] + money.at(i), M[i - 1]);
        MStartBy1[i] = max(MStartBy1[i - 2] + money.at(i), MStartBy1[i - 1]);
    }
    
    if (M[money.size() - 1] == MStartBy1[money.size() - 1]) {
        return M[money.size() - 1];
    }
    if (M[money.size() - 1] == M[money.size() - 2]) {
        return M[money.size() - 1];
    }
    return max(MStartBy1[money.size() - 1], M[money.size() - 2]);
    
}