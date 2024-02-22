#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> participantMap;
    
    // 기존에 map에 있는 값을 받아 1 올려서 다시 넣던 과정 수정
    for (int i = 0; i < participant.size(); i++) {
        participantMap[participant.at(i)]++;
    }

    // 기존에 map에 있는 값을 받아 1 내려서 다시 넣던 과정 수정
    for (int i = 0; i < completion.size(); i++) {
        participantMap[completion.at(i)]--;
    }

    // map도 iterator를 통해 앞에 있는 값부터 가져올 수 있음.
    for (map<string, int> :: iterator iter = participantMap.begin(); iter != participantMap.end(); iter++) {
        if (iter->second == 1) {
            return iter->first;
        }
    }
}