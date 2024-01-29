#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer(prices.size(), 0);

    int last = prices.size() - 1;
    for (int i = last - 1; i >= 0; --i) {
        int presentPrice = prices.at(i);
        int advance = 0;
        int j = i;

        while (true) {
            ++j;
            ++advance;

            if (presentPrice > prices.at(j)) {
                break;
            }
            if (presentPrice == prices.at(j)) {
                answer.at(i) += answer.at(j);
                break;
            }
            if (j == last) {
                break;
            }
        }

        answer.at(i) += advance;

    }

    return answer;
}