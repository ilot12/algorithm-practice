#include <vector>
#include <map>
#include <set>
#include <deque>
using namespace std;

class Graph {
private:
    int width;
    int height;
    map<pair<int, int>, vector<pair<int, int>>> adjList;

    set<pair<int, int>> walls;


public:
    //  m이 가로 n이 세로 pair의 first가 가로, second가 세로
    Graph(int n, int m, vector<vector<int>> maps) : width(m), height(n), adjList() {

        for (int i = 0; i < height; ++i) {
            vector<int> line = maps.at(i);
            for (int j = 0; j < width; ++j) {
                if (line.at(j) == 0) {
                    walls.insert({ j,i });
                }
            }
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i != height - 1) {
                    addEdge({ j, i }, { j, i + 1 });
                }
                if (j != width - 1) {
                    addEdge({ j, i }, { j + 1, i });
                }
            }
        }

    }

    void addEdge(pair<int, int> edge1, pair<int, int> edge2) {
        if (walls.find(edge1) != walls.end() || walls.find(edge2) != walls.end()) {
            return;
        }
        adjList[edge1].push_back(edge2);
        adjList[edge2].push_back(edge1);
        return;
    }

    int bfs(pair<int, int> startPoint) {
        set<pair<int, int>> visited;
        deque<pair<pair<int, int>, int>> bfsSearchQueue;

        bfsSearchQueue.push_front({ startPoint, 1 });

        while (!bfsSearchQueue.empty()) {
            pair<pair<int, int>, int> point = bfsSearchQueue.front();
            bfsSearchQueue.pop_front();
            visited.insert(point.first);

            if (point.first == make_pair(width - 1, height - 1)) {
                return point.second;
            }

            vector<pair<int, int>> pointAdjList = adjList[point.first];
            for (vector<pair<int, int>>::iterator it = pointAdjList.begin(); it != pointAdjList.end(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    bfsSearchQueue.push_back({ *it ,point.second + 1 });
                    visited.insert(*it);
                }
            }
        }
        return -1;

    }
};

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps.at(0).size();

    Graph myGraph = Graph(n, m, maps);
    return myGraph.bfs({ 0,0 });
}