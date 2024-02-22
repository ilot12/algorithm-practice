#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
vector<vector<int>> adjList;
vector<deque<string>> answers;
vector<bool> visited;
vector<vector<string>> ticketsVec;

void dfs(int ticketNum, deque<string> &strs){
    strs.push_back(ticketsVec.at(ticketNum).at(1));
    if (strs.size() == ticketsVec.size() + 1) {
        answers.push_back(strs);
    }
    for (int i = 0; i < adjList.at(ticketNum).size(); ++i) {
        if (!visited.at(adjList.at(ticketNum).at(i))) {
            visited.at(adjList.at(ticketNum).at(i)) = true;
            dfs(adjList.at(ticketNum).at(i), strs);
        }
    }
    visited.at(ticketNum) = false;
    strs.pop_back();
}
deque<string> dfsStart() {
    deque<string> strs;
    strs.push_back("ICN");
    for (int i = 0; i < ticketsVec.size(); ++i) {
        if (ticketsVec.at(i).at(0) == "ICN") {
            visited.at(i) = true;
            dfs(i, strs);
        }
    }
    
    return *min_element(answers.begin(), answers.end());
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    ticketsVec.insert(ticketsVec.end(), tickets.begin(), tickets.end());
    adjList.resize(tickets.size(), vector<int>(0));
    visited.resize(tickets.size(), false);
    for (int i = 0; i < tickets.size(); ++i) {
        for (int j = 0; j < tickets.size(); ++j) {
            if (tickets.at(i).at(1) == tickets.at(j).at(0)) {
                adjList.at(i).push_back(j);
            }
        }
    }
    deque<string> answerDeque = dfsStart();
    answer.insert(answer.end(), answerDeque.begin(), answerDeque.end());
    
    return answer;
}