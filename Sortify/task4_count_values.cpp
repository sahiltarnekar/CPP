#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Mission 4: Count Values\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        }
    }

    cout << "Count of positive numbers: " << positiveCount << endl;
    cout << "Count of negative numbers: " << negativeCount << endl;

    return 0;
}
