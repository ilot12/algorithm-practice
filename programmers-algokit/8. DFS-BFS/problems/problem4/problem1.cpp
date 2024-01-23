#include <string>
#include <vector>
#include <deque>

using namespace std;

class Graph {
private:
    int vertices;   //  begin이 0번, nr개의 words, 
    vector<vector<int>> adjList;
    int wordLength;
    int answerNumber;   //  정답이 있는지 확인해서 담은 숫자.
    
    vector<bool> visited;

    bool isLinked(string word1, string word2) {
        int wrongCount = 0;
        for (int i = 0; i < word1.length(); ++i) {
            if (word1[i] != word2[i]) {
                ++wrongCount;
                if (wrongCount == 2) {
                    return false;
                }
            }
        }
        return true;
    }

    void addEdges(int vert1, int vert2) {
        adjList.at(vert1).push_back(vert2);
        adjList.at(vert2).push_back(vert1);
        return;
    }


public:
    Graph(int V, string begin, string target, vector<string> words)
        : vertices(V + 2), adjList(V + 2) {
        
        for (int i = 0; i < V; ++i) {
            if (isLinked(begin, words[i])) {
                addEdges(0, i + 1);
            }
            if (isLinked(begin, target)) {
                addEdges(0, V + 1);
            }
        }

        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                if (isLinked(words[i], words[j])) {
                    addEdges(i + 1, j + 1);
                }
            }
            if (isLinked(words[i], target)) {
                addEdges(i + 1, V + 1);
            }
        }

        answerNumber = -1;
        for (int i = 0; i < V; i++) {
            if (words.at(i) == target) {
                answerNumber = i + 1;
            }
        }

    }

    int bfs() {
        if (answerNumber == -1) {
            return 0;
        }

        vector<int> visited(vertices, false);
        deque < pair<int, int>> bfsSearchQueue;

        visited.at(0) = true;
        bfsSearchQueue.push_back({ 0,0 });

        while (!bfsSearchQueue.empty()) {
            pair<int, int> word = bfsSearchQueue.front();
            bfsSearchQueue.pop_front();
            if (word.first == answerNumber) {
                return word.second;
            }

            vector<int> adjWords = adjList.at(word.first);
            for (int wordPosition : adjWords) {
                if (!visited[wordPosition]) {
                    bfsSearchQueue.push_back({wordPosition, word.second + 1});
                    visited[wordPosition] = true;
                }
            }
            
        }
        return 0;
    }

};

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    Graph myGraph = Graph(words.size(), begin, target, words);

    return myGraph.bfs();
}