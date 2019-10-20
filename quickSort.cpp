#include <iostream>

using namespace std;


/*
 * Swap two variables
 * 
 * @param {int*} a - First variable
 * @param {int*} b - Second variable
 */
void swap (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


/*
 * Perform partition for quicksort
 * 
 * @param {int} arr[] - Section of an array
 * @param {int} low - Starting index of the array
 * @param {int} high - Upper limit index of the array
 */

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}


/*
 * Perform quicksort algorithm to sort elements in an array in ascending order
 * 
 * @param {int} arr[] - Array to be sorted
 * @param {int} low - Starting index of the array
 * @param {int} high - Upper limit index of the array
 */
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


int main() {
    int array1[10] = {1, 4, 2, 0, 3, 6, 8, 7, 9, 5};
    quicksort(array1, 0, 10);
    for (int i = 0; i < 10; i++)
        cout << array1[i] << "\t";
    cout << endl;
}