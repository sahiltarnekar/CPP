#include <iostream>

using namespace std;

// Function to sort an array in ascending order using Bubble Sort
void bubbleSortAscending(int arr[], int n) {
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

// Function to sort an array in descending order using Bubble Sort
void bubbleSortDescending(int arr[], int n) {
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
    cout << "Mission 3: Sort Squad\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arrAsc[100], arrDesc[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arrAsc[i] = temp;
        arrDesc[i] = temp;
    }

    bubbleSortAscending(arrAsc, n);
    bubbleSortDescending(arrDesc, n);

    cout << "Array in Ascending Order: ";
    for (int i = 0; i < n; i++) {
        cout << arrAsc[i] << " ";
    }
    cout << endl;

    cout << "Array in Descending Order: ";
    for (int i = 0; i < n; i++) {
        cout << arrDesc[i] << " ";
    }
    cout << endl;

    return 0;
}
