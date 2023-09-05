#include <iostream>

#include <vector>

#include <unordered_map>

#include <algorithm>

using namespace std;
int main() {
    int frames;
    cout << "S.Navaneetha Krishnan 21BCE1351\n";
    cout << "Enter the number of frames: ";
    cin >> frames;
    vector < int > MainMemory(frames, -1);
    vector < int > RequestTable;
    cout << "Enter count request: ";
    int Request;
    cin >> Request;
    cout << "Enter values: ";
    int a;
    for (int i = 0; i < Request; i++) {
        cin >> a;
        RequestTable.push_back(a);
    }
    int hitCount = 0;
    int missCount = 0;
    int time = 0;
    while (time < RequestTable.size()) {
        int RequestValue = RequestTable[time];
        auto itr = find(MainMemory.begin(), MainMemory.end(), RequestValue);
        if (itr != MainMemory.end()) {
            // Page hit
            hitCount++;
        } else {
            // Page miss
            missCount++;
            if (MainMemory.size() == frames) {
                // Find the page with the furthest future position
                int maxFuturePos = -1;
                int pageToReplace = -1;
                unordered_map < int, int > futurePos;
                for (int i = time + 1; i < RequestTable.size(); i++) {
                    futurePos[RequestTable[i]] = i;
                }
                for (int i = 0; i < MainMemory.size(); i++) {
                    if (futurePos.find(MainMemory[i]) == futurePos.end()) {
                        // Page not found in future positions, choose it for
                        replacement
                        pageToReplace = i;
                        break;
                    } else {
                        if (futurePos[MainMemory[i]] > maxFuturePos) {
                            maxFuturePos = futurePos[MainMemory[i]];
                            pageToReplace = i;
                        }
                    }
                }
                MainMemory[pageToReplace] = RequestValue;
            } else {
                // There is still space in MainMemory, so add the page to an empty
                frame
                MainMemory.push_back(RequestValue);
            }
        }
        // Print the frame data
        cout << time << "\t";
        for (int i = 0; i < frames; i++) {
            if (i < MainMemory.size()) {
                cout << MainMemory[i] << "\t";
            } else {
                cout << "$\t";
            }
        }
        cout << "\n";
        time++;
    }
    cout << "Hits: " << hitCount << endl;
    cout << "Misses: " << missCount << endl;
    return 0;
}
