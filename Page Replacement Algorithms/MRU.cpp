#include<iostream>

#include<vector>

#include<algorithm>

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
    int counter = 0;
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
                // Remove the most recently used page
                MainMemory.pop_back();
            }
        }
        if (itr != MainMemory.end()) {
            // Remove the current page request value
            MainMemory.erase(itr);
        }
        // Insert the current page request value
        MainMemory.push_back(RequestValue);
        // Print the frame datacout << time << "\t";
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
