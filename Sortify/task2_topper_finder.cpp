#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int n;
    cout << "Mission 2: Topper Finder\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 1) {
        cout << "Array should have at least one element." << endl;
        return 0;
    }

    int arr[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (largest == INT_MIN && n > 0) {
        // Handle edge case where elements might be INT_MIN
        largest = arr[0]; 
        for(int i = 0; i < n; i++) {
            if(arr[i] > largest) largest = arr[i];
        }
    }

    cout << "The largest number is: " << largest << endl;
    
    if (secondLargest == INT_MIN) {
        cout << "No second largest number found (all elements might be the same or only 1 element given)." << endl;
    } else {
        cout << "The second largest number is: " << secondLargest << endl;
    }

    return 0;
}
