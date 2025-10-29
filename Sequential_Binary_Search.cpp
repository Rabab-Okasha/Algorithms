#include <iostream>
#include <vector>
using namespace std;

int SequentialSearch(const vector<int>& arr, int target){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target) // target found
            return i;
    }
    return -1;
}

int RSequentialSearch(const vector<int>& arr, int target){
    if(arr.empty())
        return -1; // if vector is empty then target not found

    if(arr[0] == target)
        return 0; // target found

    // create another vector without the first element
    vector<int> arr_small(arr.begin() + 1 , arr.end());
    int result = RSequentialSearch(arr_small, target);

    if(result == -1)
        return -1; // target not found in smaller vector
    else
        return result + 1; // return the correct index as we removed the first element from it
}

int BinarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int middle = (right + left) / 2;
        // target is found
        if (arr[middle] == target)
            return middle;

        else if (arr[middle] < target)
            left = middle + 1; //search in right half
        else
            right = middle - 1; // search in left half
    }
    return -1;
}

int RBinarySearch(const vector<int>& arr, int target, int low, int high) {
    int middle = (high + low) / 2;

    // if range is invalid, low greater than high
    if(low > high)
        return -1;

    // target is found
    if(arr[middle] == target)
        return middle;

    else if(arr[middle] < target)
        return RBinarySearch(arr, target, middle + 1, high); // search right half
    else
        return RBinarySearch(arr, target, low, middle - 1);// search left half
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;
    int index;

    cout << "The list: [ ";
    bool first = true;
    for(int n : list){
        if(!first)
            cout << ", ";
        cout << n;
        first = false;
    }
    cout << " ]";
    
    cout << "\nEnter your target: " ;
    cin >> target;

    cout << "-----Sequential search (iterative)-----" << endl;
    index = SequentialSearch(list, target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    cout << "\n-----Sequential search (Recursive)-----" << endl;
    index = RSequentialSearch(list,target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    cout << "\n-----Binary search (iterative)-----" << endl;

    index = BinarySearch(list, target);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    cout << "\n-----Binary search (Recursive)-----" << endl;
    int high = list.size() - 1;
    index = RBinarySearch(list, target, 0, high);
    if (index == -1)
        cout << "Target not found!" << endl;
    else
        cout << "Target found at index: " << index << endl;

    return 0;
}
