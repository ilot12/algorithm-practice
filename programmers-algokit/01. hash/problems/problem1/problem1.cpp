#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> participantMap;
    
    for (int i = 0; i < participant.size(); i++) {
        string person = participant.at(i);
        int count = participantMap[person];
        participantMap[person] = ++count;
    }

    for (int i = 0; i < completion.size(); i++) {
        string person = completion.at(i);
        int count = participantMap[person];
        participantMap[person] = --count;
    }

    for (int i = 0; i < participant.size(); i++) {
        string person = participant.at(i);
        if (participantMap[person] == 1) {
            return person;
        }
    }

    return answer;
}