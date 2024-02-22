#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
private:
    int vertex;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<vector<int>> wiresVec;
    
    void makeAdjList(vector<vector<int>> wires) {
        for (vector<int> wire : wires) {
            addEdge(wire);
        }
    }
    
    void addEdge(vector<int> wire) {
        int vert1 = wire.at(0);
        int vert2 = wire.at(1);
        adjList.at(vert1).push_back(vert2);
        adjList.at(vert2).push_back(vert1);
    }
public:
    Graph(int n, vector<vector<int>> wires):
        vertex(n + 1), 
        adjList(n + 1),
        visited(n + 1, false) {
            makeAdjList(wires);
            wiresVec = wires;
        }
    
    int bfsStart(int start, int disabledEdge) {
        vector<bool> emptyVisited(vertex, false);
        visited = emptyVisited;
        int counts = 1;
        queue<int> bfsSearchQueue;
        bfsSearchQueue.push(start);
        visited[start] = true;
        while (!bfsSearchQueue.empty()) {
            int present = bfsSearchQueue.front();
            bfsSearchQueue.pop();
            for (int num : adjList.at(present)) {
                if (num == disabledEdge) {
                    continue;
                }
                if (!visited[num]) {
                    counts++;
                    bfsSearchQueue.push(num);
                    visited[num] = true;
                }
            }
        }
        
        return counts;
    }
    
    int findAnswer() {
        int answer = 100;
        for (vector<int> wire: wiresVec) {
            int vert1 = wire.at(0);
            int vert2 = wire.at(1);
            int diff = bfsStart(vert1, vert2) - bfsStart(vert2, vert1);
            if (diff < 0) {
                diff = -diff;
            }
            answer = min(diff, answer);
        }

        return answer;
    }
};

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    Graph myGraph = Graph(n, wires);
    
    return myGraph.findAnswer();
}