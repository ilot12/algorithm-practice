#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> moveCounts;

    void addEdges(vector<int> oneEdge) {
        int vertex1 = oneEdge[0];
        int vertex2 = oneEdge[1];
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

public:
    Graph(int n, vector<vector<int>> edge)
        : vertices(n + 1), adjList(n + 1), visited(n + 1, false), moveCounts(n + 1) {
        //  edge에 node가 1번부터 시작하기에 실제 n+1의 size를 가지고 1번자리에 1번노드가 가도록 함.
        for (vector<int> oneEdge : edge) {
            addEdges(oneEdge);
        }
    }

	//
    void bfs() {
        deque <int> bfsSeachQueue;
        bfsSeachQueue.push_back(1);
        visited[1] = true;
        moveCounts[1] = 0;

        while (!bfsSeachQueue.empty()) {
            int presentNode = bfsSeachQueue.front();
            bfsSeachQueue.pop_front();

            vector<int> adjNodes = adjList[presentNode];
            for (int adjNode : adjNodes) {
                if (!visited[adjNode]) {
                    bfsSeachQueue.push_back(adjNode);
                    moveCounts[adjNode] = moveCounts[presentNode] + 1;
                    visited[adjNode] = true;
                }
            }
        }

    }

    int farElements() {
        int maxDistance = *max_element(moveCounts.begin(), moveCounts.end());
        int count = 0;
        for (int move : moveCounts) {
            if (move == maxDistance) {
                ++count;
            }
        }
        return count;
    }

};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    Graph myGraph(n, edge);
    myGraph.bfs();

    return myGraph.farElements();
}