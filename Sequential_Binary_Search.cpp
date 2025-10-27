#include <iostream>
using namespace std;

int SequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int RSequentialSearch(int arr[], int size, int target, int i = 0) {
    if (size == i)
        return -1;
    if (arr[i] == target)
        return i;
    return RSequentialSearch(arr, size, target, i + 1);
}

int BinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = (right + left) / 2;
        if (arr[middle] == target)
            return middle;
        else if (arr[middle] < target)
            left = middle + 1; //search in left half
        else
            right = middle - 1; // search in right half
    }
    return -1;
}

int RBinarySearch(int arr[], int left, int right, int target) {
    int middle = (right + left) / 2;

    if(left > right)
        return -1;

    if(arr[middle] == target)
        return middle;
    else if(arr[middle] < target)
        return RBinarySearch(arr, middle + 1, right, target);
    else
        return RBinarySearch(arr, left, middle - 1, target);
}

int main() {
    int list[] = {2, 5, 8, 3, 6, 9, 1, 4, 7};
    int size = sizeof(list) / sizeof(list[0]);
    int target = 6;

    cout << "-----Sequential search (iterative)-----" << endl;
    int index = SequentialSearch(list, size, target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    cout << "\n-----Sequential search (Recursive)-----" << endl;
    index = RSequentialSearch(list, size, target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    cout << "\n-----Binary search (iterative)-----" << endl;
    index = BinarySearch(list, size, target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    cout << "\n-----Binary search (Recursive)-----" << endl;
    int low = 0;
    int high = size - 1;
    index = RBinarySearch(list, low, high, target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    return 0;
}