#include <string>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int vertex;
    vector<int> winOrLoseCount;
    vector<set<int>> playersIndexCanWin;
    vector<set<int>> playersIndexLoseTo;

    void addEdge(int winner, int loser) {
        if (!playersIndexCanWin.at(winner).insert(loser).second) {
            return;
        }
        playersIndexLoseTo.at(loser).insert(winner);
        winOrLoseCount.at(winner)++;
        winOrLoseCount.at(loser)++;
    }

    void addOtherEdges(vector<int> result) {
        int winner = result.at(0);
        int loser = result.at(1);
        addEdge(winner, loser);
        for (int loserOfLoser : playersIndexCanWin.at(loser)) {
            addEdge(winner, loserOfLoser);
        }
        for (int winnerOfWinner : playersIndexLoseTo.at(winner)) {
            addEdge(winnerOfWinner, loser);
        }
        for (int loserOfLoser : playersIndexCanWin.at(loser)) {
            for (int winnerOfWinner : playersIndexLoseTo.at(winner)) {
                addEdge(winnerOfWinner, loserOfLoser);
            }
        }
    }

public:
    Graph(int n, vector<vector<int>> results) :
        vertex(n + 1), 
        winOrLoseCount(n + 1, 0), 
        playersIndexCanWin(n + 1),
        playersIndexLoseTo(n + 1)
    {
        for (vector<int> result : results) {
            addOtherEdges(result);
        }
    }

    int countRanks() {
        int answer = 0;
        for (int count : winOrLoseCount) {
            if (count == vertex - 2) {
                answer++;
            }
        }
        return answer;
    }

};

int solution(int n, vector<vector<int>> results) {

    Graph myGraph = Graph(n, results);


    return myGraph.countRanks();
}