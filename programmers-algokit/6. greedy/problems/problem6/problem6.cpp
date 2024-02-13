#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int findCamera(deque<vector<int>> routesDeque) {
    int camera = routesDeque.at(0).at(1);
    for (vector<int> route : routesDeque) {
        camera = min(camera, route.at(1));
    }
    return camera;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    
    deque<vector<int>> routesDeque(routes.begin(), routes.end());
    sort(routesDeque.begin(), routesDeque.end());
    
    while(!routesDeque.empty()) {
        answer++;
        int camera = findCamera(routesDeque);
        while(!routesDeque.empty()){
            if (routesDeque.front().at(0) <= camera) {
                routesDeque.pop_front();
            } else {
                break;
            }
        }
    }
    
    return answer;
}