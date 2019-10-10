#include <iostream>
using namespace std;

int binSearch(int arr[], int bot, int top, int sFor, int& clock) {
    clock++;
    int mid = (top + bot)/2;
    if (top != bot) {
        if (arr[mid] == sFor)
            return (mid+1);
        else {
            if (sFor < arr[mid])
                binSearch(arr, bot, mid, sFor, clock);
            else
                binSearch(arr, (mid+1), top, sFor, clock);
        }
    } else {
        return -1;
    }
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int b = 0;
    
    int step = 0;

    for (int i = 0; i < 10; i++)
        cout << a[i] << "\t";

    cout << "\n\nInput number to search: ";
    cin >> b;

    cout << endl << endl;

    cout << "Position: " << binSearch(a, 0, 10, b, step) << endl;
    cout << "Step: " << step << endl;
}