#include<iostream>
#include<vector>
using namespace std;

int main() {
    int frames;
    cout << "S.Navaneetha Krishnan 21BCE1351 \n" << "Enter the number of
    frames " << endl;
    cin >> frames;
    vector < int > MainMemory(frames, -1);
    vector < int > RequestTable;
    cout << "Enter count request" << endl;
    int Request;
    cin >> Request;
    int a;
    cout << "Enter values" << endl;
    for (int i = 0; i < Request; i++) {
        cin >> a;
        RequestTable.push_back(a);
    }
    int counter = 0;
    int checker = 0;
    int hitCount = 0;
    int missCount = 0;
    int label = 0;
    int time = 0;
    while (label < RequestTable.size()) {
        int RequestValue = RequestTable[label];
        int flag = true;
        for (int i = 0; i < frames; i++) {
            if (MainMemory[i] == RequestValue) {
                hitCount++;
                flag = false;
            }
        }
        if (flag) {
            missCount++;
            MainMemory[counter] = RequestValue;
            counter++;
        }
        label++;
        counter = counter % frames;
        cout << time << "\t ";
        for (int i = 0; i < frames; i++) {
            if (MainMemory[i] != -1) {
                cout << MainMemory[i] << "\t";
            } else {
                cout << '$' << "\t";
            }
        }
        cout << "\n";
        time++;
    }
    return 0;
}
