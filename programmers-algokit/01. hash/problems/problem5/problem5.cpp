#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    //  이 map에 key는 장르고, value로는 총합이 들어있음.
    map<string, int> playsEachGenre;

    //  이 map은 답을 만들어내기위한 map으로 key에는 장르가 들어있고 value는 {재생수,번호}인 pair의 벡터
    map<string, vector<pair<int, int>>> playsEachGenreNumber;
    
    for (int i = 0; i < genres.size(); ++i) {
        string genre = genres.at(i);
        int play = plays.at(i);

        if (playsEachGenre.find(genre) == playsEachGenre.end()) {
            playsEachGenre.insert({ genre, play });
            vector<pair<int, int>> playsThisGenreNumber({ {play,i} });
            playsEachGenreNumber.insert({ genre,playsThisGenreNumber });
        }
        else {
            playsEachGenre[genre] += play;
            playsEachGenreNumber[genre].push_back({ play,i });
        }
    }

    vector<pair<string, int>> playsEachGenreVector(playsEachGenre.begin(), playsEachGenre.end());

    for (map<string, vector<pair<int, int>>>::iterator it = playsEachGenreNumber.begin(); it != playsEachGenreNumber.end(); ++it) {
        sort(it->second.begin(), it->second.end(), [](pair<int, int> a, pair<int, int> b) -> bool{
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a > b;
        });
    }

    sort(playsEachGenreVector.begin(), playsEachGenreVector.end(), [](pair<string, int> a, pair<string, int> b) -> bool {
        return a.second > b.second;
        });

    for (pair<string, int> genrePlaysPair : playsEachGenreVector) {
        vector<pair<int, int>> playsThisGenreVector = playsEachGenreNumber[genrePlaysPair.first];
        if (playsThisGenreVector.size() >= 2) {
            answer.push_back(playsThisGenreVector.at(0).second);
            answer.push_back(playsThisGenreVector.at(1).second);
        }
        else {
            answer.push_back(playsThisGenreVector.at(0).second);
        }
    }

    return answer;
}
