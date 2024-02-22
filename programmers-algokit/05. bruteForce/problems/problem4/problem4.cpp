#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int height = 1;
    int width;
    for (height; height <= yellow; ++height) {
        if (yellow % height != 0) {
            continue;
        }
        width = yellow / height;
        if (brown == 2 * width + 2 * height + 4) {
            break;
        }
    }
    answer.push_back(width + 2);
    answer.push_back(height + 2);
    
    return answer;
}