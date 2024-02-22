//	미완성.
//	map을 vector로 받아와서 sort하는 과정 대신 set을 사용했음.
//	하지만 set에서 비교연산인 operator를 설정하는 과정이 훨신 복잡해서 굳이 사용해야 되나 싶었음.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

struct compare2 {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

map<string, set<pair<int, int>, compare>> playlist;
map<string, int> counts;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer(1, 0);
    for (int i = 0; i < genres.size(); i++) {
        string genre = genres.at(i);
        int play = plays.at(i);
        counts[genre] += play;

        if (playlist.find(genre) == playlist.end()) {
            set<pair<int, int>, compare> mySet;
            playlist.insert({ genre, mySet });
        }
        playlist[genre].insert({ play,i });
    }

    map<int, string, compare2> sortedCounts;
    for (pair<string, int> eachCount : counts) {
        sortedCounts.insert({ eachCount.second, eachCount.first });
    }

    for (pair<int, string> eachSortedCount : sortedCounts) {
        cout << eachSortedCount.first << ", " << eachSortedCount.second << "\n";
    }

    return answer;
}
int main() {

    vector<string> genres({ "classic", "pop", "classic", "classic", "pop" });
    vector<int> plays({ 500, 600, 150, 800, 2500 });
    solution(genres, plays);
    return 0;
}