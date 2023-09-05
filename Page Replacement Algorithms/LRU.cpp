#include <iostream>

#include <vector>

#include <algorithm>int main() {

int frames;
std::cout << "S.Navaneetha Krishnan 21BCE1351\n";
std::cout << "Enter the number of frames: ";
std::cin >> frames;
std::vector < int > MainMemory(frames, -1);
std::vector < int > RequestTable;
std::cout << "Enter count request: ";
int Request;
std::cin >> Request;
std::cout << "Enter values: ";
int a;
for (int i = 0; i < Request; i++) {
    std::cin >> a;
    RequestTable.push_back(a);
}
int counter = 0;
int hitCount = 0;
int missCount = 0;
int time = 0;
while (time < RequestTable.size()) {
    int RequestValue = RequestTable[time];
    auto
    itr
        =
        std::find(MainMemory.begin(),
            MainMemory.end(),
            RequestValue);
    if (itr != MainMemory.end()) {
        // Page hit
        hitCount++;
        MainMemory.erase(itr);
    } else {
        // Page miss
        missCount++;
        if (MainMemory.size() == frames) {
            // Remove the least recently used page
            MainMemory.erase(MainMemory.begin());
        }
    }
    // Insert the current page request value
    MainMemory.push_back(RequestValue);
    // Print the frame data
    std::cout << time << "\t";
    for (int i = 0; i < frames; i++) {
        if (i < MainMemory.size()) {
            std::cout << MainMemory[i] << "\t";
        } else {
            std::cout << "$\t";
        }
    }
    std::cout << "\n";
    time++;
}
std::cout << "Hits: " << hitCount << std::endl;
std::cout << "Misses: " << missCount << std::endl;
return 0;
}
