#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, vector<string>> types;

    for (vector<string> cloth : clothes) {
        string clothType = cloth.at(1);
        string clothName = cloth.at(0);

        if (types.find(clothType) == types.end()) {
            vector<string> specificType({clothName});
            types.insert({ clothType, specificType });
        }
        else {
            types[clothType].push_back(clothName);
        }
    }

    for (map<string, vector<string>>::iterator it = types.begin(); it != types.end(); ++it) {
        answer *= (it->second.size() + 1);
    }

    return answer - 1;
}
