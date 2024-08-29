#include<iostream>
using namespace std;

// Function prototypes
int array_output(int arr[], int n);
int array_input(int arr[], int n);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void swap(int &a, int &b);

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function 
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // pivot element
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot && j > low) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

// Quick sort 
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1); // Recursive call for elements less than pivot
        quick_sort(arr, pivot + 1, high); // Recursive call for elements greater than pivot
    }
}

int array_output(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Array element -> " << arr[i] << endl;
    }
    return 0;
}

int array_input(int arr[], int n) {
    cout << "Size of array = " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    
    array_input(arr, n);
    quick_sort(arr, 0, n - 1);  // Call quick_sort on the entire array
    array_output(arr, n);       // Display sorted array
    
    return 0;
}
