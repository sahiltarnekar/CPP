#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Mission 1: Remove the Twins\n";
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int uniqueArr[100];
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        // Check if the element is already in uniqueArr
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        // If not a duplicate, add to uniqueArr
        if (!isDuplicate) {
            uniqueArr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;

    return 0;
}
