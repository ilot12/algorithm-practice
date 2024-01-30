#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer(prices.size());
    stack<int> priceAdvance;

    for (int i = 0; i < prices.size(); ++i) {
        while (!priceAdvance.empty() && prices.at(priceAdvance.top()) > prices.at(i)) {
            answer.at(priceAdvance.top()) = i - priceAdvance.top();
            priceAdvance.pop();
        }
        priceAdvance.push(i);
    }
    while (!priceAdvance.empty()) {
        answer.at(priceAdvance.top()) = prices.size() - 1 - priceAdvance.top();
        priceAdvance.pop();
    }


    return answer;
}