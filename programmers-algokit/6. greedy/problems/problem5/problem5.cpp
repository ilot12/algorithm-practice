#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
    
vector<bool> linked;
deque<vector<int>> outerEdges;
vector<vector<vector<int>>> edgesOfEachVertex;
int costSum;

void insertVertex(int n) {
    linked.at(n) = true;    
    for (vector<int> edge : edgesOfEachVertex.at(n)) {
        outerEdges.push_back(edge);
    }
}

void deleteInnerEdges() {
    deque<vector<int>> newOuterEdges;
    for (vector<int> edge : outerEdges) {
        if (linked.at(edge.at(0)) && linked.at(edge.at(1))){
            continue;
        }
        newOuterEdges.push_back(edge);
    }
    outerEdges = newOuterEdges;
}

int findNextVertex() {
    sort(outerEdges.begin(), outerEdges.end(), [](
        vector<int> a, vector<int> b) -> bool{
            return a.at(2) < b.at(2);
        });
    vector<int> newEdge = outerEdges.at(0);
    costSum += newEdge.at(2);
    if (linked.at(newEdge.at(0))){
        return newEdge.at(1);
    }
    return newEdge.at(0);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    costSum = 0;
    vector<bool> vector_size_n(n);
    linked = vector_size_n;
    vector<vector<vector<int>>> edgesOfEachVertex_size_n(n);
    edgesOfEachVertex = edgesOfEachVertex_size_n;
    
    for (vector<int> edge: costs) {
        int vert1 = edge.at(0);
        int vert2 = edge.at(1);
        edgesOfEachVertex.at(vert1).push_back(edge);
        edgesOfEachVertex.at(vert2).push_back(edge);
    }

    insertVertex(0);
    for (int i = 0; i < n - 1; ++i) {
        deleteInnerEdges();
        int nextVertex = findNextVertex();
        insertVertex(nextVertex);
    }
    
    answer = costSum;
    
    
    return answer;
}