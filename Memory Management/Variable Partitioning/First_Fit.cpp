#include <iostream>

#include <iomanip>

#include <vector>

#include <algorithm>

#include <climits>

using namespace std;
// This is the coding of the Variable First fit first.
// When alloting to a block.
// There is no point of internal Fragmentation in this .
int main() {
    int block;
    int files;
    cout << "21BCE1351 S.Navaneetha Krishnan" << endl;
    cout << "Enter number of blocks: ";
    cin >> block;
    int usedBlock;
    cout << "Enter the number of used Blocks" << endl;
    cin >> usedBlock;
    cout << "Enter number of files: ";
    cin >> files;
    vector < int > BlockSize;
    vector < int > CopyBlockSize;
    vector < int > FileSize;
    int a;
    cout << "Enter the size of blocks:" << endl;
    for (int i = 0; i < block; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> a;
        BlockSize.push_back(a);
    }
    CopyBlockSize = BlockSize;
    cout << "Enter the used BlockNumber";
    int z;
    for (int i = 0; i < usedBlock; i++) {
        // These blocks cannot be used any more.
        cin >> z;
        BlockSize[z - 1] = 0;
        CopyBlockSize[z - 1] = 0;
    }
    cout << "Enter the size of the file:" << endl;
    for (int i = 0; i < files; i++) {
        cout << "File " << i + 1 << ": ";
        cin >> a;
        FileSize.push_back(a);
    }
    cout << "OUTPUT" << endl;
    cout << setw(8) << "File No" << setw(12) << "File Size" << setw(10) << "Block
    No " << setw(12) << "
    Block Size " << setw(10) << "
    IFragment " << endl;
    int InternalFragment = 0;
    int ExternalFragment = 0;
    vector < int > Alloted(block, 0);
    int maxRequired = INT_MIN;
    bool currAllot = false;
    for (int i = 0; i < files; i++) {
        for (int j = 0; j < block; j++) {
            if (BlockSize[j] >= FileSize[i]) {
                int frag = BlockSize[j] - FileSize[i];
                BlockSize[j] -= FileSize[i];
                cout << setw(8) << i + 1 << setw(12) << FileSize[i] << setw(10) << j + 1 <<
                    setw(12) << BlockSize[j] << setw(10) << frag << endl;
                currAllot = true;
                break;
            }
        }
        if (!currAllot) {
            cout << setw(8) << i + 1 << setw(12) << FileSize[i] << setw(10) << "----" <<
                setw(12) << "-----" << setw(10) << "-----" << endl;
            maxRequired = max(maxRequired, FileSize[i]);
        }
        currAllot = false;
    }
    // We need to calulate the External Fragmentation.
    // Calulate the total remaining places in each block.
    int sum = 0;
    for (int i = 0; i < block; i++) {
        sum += (BlockSize[i]);
    }
    if (sum >= maxRequired) {
        cout << "Total amount of External Fragmentation: " << maxRequired << endl;
    } else {
        cout << "Total amount of Internal Fragmentation: 0" << endl;
    }
}
