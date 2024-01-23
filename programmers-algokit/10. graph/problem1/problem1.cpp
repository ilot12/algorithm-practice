#include <iostream>
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

    void bfs() {
        deque < pair<int, int>> bfsSeachQueue;
        bfsSeachQueue.push_back({ 1, 0 });
        visited[1] = true;
        moveCounts[1] = 0;

        while (!bfsSeachQueue.empty()) {
            pair<int, int> presentNode = bfsSeachQueue.front();
            bfsSeachQueue.pop_front();

            vector<int> adjNodes = adjList[presentNode.first];
            for (int adjNode : adjNodes) {
                if (!visited[adjNode]) {
                    bfsSeachQueue.push_back({ adjNode, presentNode.second + 1 });
                    moveCounts[adjNode] = presentNode.second + 1;
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
int main() {
    int n = 6;
    vector<int> edge1({ 3,6 });
    vector<int> edge2({ 4,3 });
    vector<int> edge3({ 3,2 });
    vector<int> edge4({ 1,3 });
    vector<int> edge5({ 1,2 });
    vector<int> edge6({ 2,4 });
    vector<int> edge7({ 5,2 });
    
    vector<vector<int>> edge({ edge1,edge2,edge3,edge4,edge5,edge6,edge7 });
    cout << solution(n, edge);

    return 0;
}