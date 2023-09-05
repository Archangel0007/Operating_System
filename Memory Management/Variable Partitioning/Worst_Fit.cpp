#include <iostream>

#include <iomanip>

#include <vector>

#include <algorithm>

#include <climits>

using namespace std;
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
    int totalInternalFragmentation = 0;
    int totalExternalFragmentation = 0;
    vector < int > Alloted(block, 0);
    bool currAllot = false;
    for (int i = 0; i < files; i++) {
        int worstFitBlockIndex = -1;
        int maxFragment = INT_MIN;
        for (int j = 0; j < block; j++) {
            if (BlockSize[j] >= FileSize[i]) {
                int frag = BlockSize[j] - FileSize[i];
                if (frag > maxFragment) {
                    maxFragment = frag;
                    worstFitBlockIndex = j;
                }
            }
        }
        if (worstFitBlockIndex != -1) {
            BlockSize[worstFitBlockIndex] -= FileSize[i];
            cout << setw(8) << i + 1 << setw(12) << FileSize[i] << setw(10) <<
                worstFitBlockIndex + 1 << setw(12) << BlockSize[worstFitBlockIndex] << setw(10) <<
                maxFragment << endl;
            currAllot = true;
        }
        if (!currAllot) {
            cout << setw(8) << i + 1 << setw(12) << FileSize[i] << setw(10) << "----" <<
                setw(12) << "-----" << setw(10) << "-----" << endl;
            totalInternalFragmentation += FileSize[i];
        }
        currAllot = false;
    }
    int totalRemainingSpace = 0;
    for (int i = 0; i < block; i++) {
        if (BlockSize[i] > 0) {
            totalRemainingSpace += BlockSize[i];
        }
    }
    totalExternalFragmentation
        =
        max(totalRemainingSpace,
            totalInternalFragmentation);
    cout << "Total amount of Internal Fragmentation: " << totalInternalFragmentation <<
        endl;
    cout
        <<
        "Total
    amount
        of
        External
    Fragmentation:
        " <<
        totalExternalFragmentation << endl;
    return 0;
}
