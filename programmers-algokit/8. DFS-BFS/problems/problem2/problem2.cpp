#include <string>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    
    int networkCount;
    vector<bool> visited;

public:
    Graph(int V, vector<vector<int>> computers) 
        : vertices(V), adjList(V), networkCount(0), visited(V) {
        
        for (int i = 0; i < computers.size(); ++i) {
            for (int j = i + 1; j < computers.size(); ++j) {
                if (computers.at(i).at(j)) {
                    addEdges(i, j);
                }
            }
        }

    }

    void addEdges(int vert1, int vert2) {
        adjList.at(vert1).push_back(vert2);
        adjList.at(vert2).push_back(vert1);
        return;
    }

    int dfsStart() {
        networkCount = 0;
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i);
                ++networkCount;
            }
        }
        return networkCount;
    }

    void dfs(int start) {
        for (int linkedVert: adjList.at(start)) {
            if (!visited[linkedVert]) {
                visited[linkedVert] = true;
                dfs(linkedVert);
            }
        }
    }

};

int solution(int n, vector<vector<int>> computers) {
    Graph myGraph = Graph(n, computers);
    
    return myGraph.dfsStart();
}