#include <string>
#include <vector>
#include <deque>

using namespace std;

class Bridge {
private:
    int bridge_length;
    int bridgeLimitWeight;
    deque<int> watingTrucks;
    int presentBridgeWeight = 0;
    deque<int> timeTruckAtBridgeEnd;
    deque<int> presentTrucksOnBridge;
    int nextCheckTime = 0;
    int presentTime = 0;

    bool canlLoadTruck(int time) {
        presentBridgeWeight = weightAfterOneTime();
        if (presentBridgeWeight + watingTrucks.front() <= bridgeLimitWeight) {
            return true;
        }
        return false;
    }

    int weightAfterOneTime() {
        return presentBridgeWeight -= doesTruckPassAfterOneTime();
    }

    int doesTruckPassAfterOneTime() {
        if (presentTrucksOnBridge.empty()) {
            return 0;
        }
        if (timeTruckAtBridgeEnd.empty()) {
            return 0;
        }
        if (timeTruckAtBridgeEnd.front() == presentTime) {
            int temp = presentTrucksOnBridge.front();
            presentTrucksOnBridge.pop_front();
            timeTruckAtBridgeEnd.pop_front();
            return temp;
        }
        return 0;
    }

    void loadTruck() {
        presentBridgeWeight += watingTrucks.front();
        presentTrucksOnBridge.push_back(watingTrucks.front());
        timeTruckAtBridgeEnd.push_back(presentTime + bridge_length);
        watingTrucks.pop_front();
    }

public:
    Bridge(int bridge_length, int weight, vector<int> truck_weights) :
        bridge_length(bridge_length),
        bridgeLimitWeight(weight),
        watingTrucks(truck_weights.begin(), truck_weights.end()) {
    }

    int mainLoop() {
        int answer = 0;

        while (!watingTrucks.empty()) {

            if (canlLoadTruck(presentTime)) {
                loadTruck();
                presentTime += 1;
            } else {
                presentTime = timeTruckAtBridgeEnd.front();
            }
        }

        answer = timeTruckAtBridgeEnd.back() + 1;

        return answer;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    Bridge myBridge = Bridge(bridge_length, weight, truck_weights);;
    answer = myBridge.mainLoop();

    return answer;
}