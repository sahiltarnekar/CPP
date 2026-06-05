#include <iostream>

using namespace std;

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Mission 5: Magic Sorter\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int evens[100], odds[100];
    int evenCount = 0, oddCount = 0;

    // Separate into even and odd arrays
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];
        } else {
            odds[oddCount++] = arr[i];
        }
    }

    // Sort even numbers in ascending order
    sortAscending(evens, evenCount);
    // Sort odd numbers in descending order
    sortDescending(odds, oddCount);

    int result[100];
    int index = 0;
    
    // Merge even numbers first
    for (int i = 0; i < evenCount; i++) {
        result[index++] = evens[i];
    }
    // Merge odd numbers second
    for (int i = 0; i < oddCount; i++) {
        result[index++] = odds[i];
    }

    cout << "Array after sorting evens (ascending) and odds (descending): ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
