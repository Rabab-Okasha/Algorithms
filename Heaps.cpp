#include <iostream>
using namespace std;

// task 3
class Heap {
private:
    int priority[100]; // priorities for queue
    int pqArr[100];    // queue elements
    int pqSize;        // queue size
    int arr[100];      // heap array
    int Size;          // heap size
    int Sorted[100];   // sorted array

public:
    Heap() { // constructor
        Size = 0;
        pqSize = 0;
    }

    void setSize(int a) { Size = a; }
    int getSize() { return Size; }
    int getPriority(int i) { return priority[i]; }

    // heap functions
    void Insert(int arr[], int key, int& n);
    void MaxHeapify(int arr[], int index, int n);
    int ExtractMax(int arr[], int& n);
    int ExtractMin(int arr[], int& n);
    void IncreaseKey(int arr[], int i, int key);
    void printHeap(int A[]);
    void BuildMaxHeap(int arr[], int Size);

    // priority queue functions
    void IncreaseKey(int i, int key, int Priority);
    void ExtractMaxP();
    void Insert(int key, int Priority);
    void MaxHeapifyP(int i);
    void printPriorityQueue();

    // sorting
    void SortedArray(int arr[], int& n);
};

// swap two numbers
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// keep max-heap property
void Heap::MaxHeapify(int arr[], int i, int Size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    // check left child
    if (left < Size && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < Size && arr[right] > arr[largest])
        largest = right;

    // if largest is not parent, swap
    if (largest != i) {
        Swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, Size); // recursive call
    }
}

// remove and return max element
int Heap::ExtractMax(int arr[], int &n) {
    if (n < 1) {
        cout << "Heap is empty" << endl;
        return -1;
    }

    int Max = arr[0]; // root is max
    arr[0] = arr[n - 1]; // move last to root
    n--; // reduce size
    MaxHeapify(arr, 0, n); // fix heap
    return Max;
}

// remove and return min element
int Heap::ExtractMin(int arr[], int &n) {
    if (n < 1) {
        cout << "Heap is empty" << endl;
        return -1;
    }

    int MinIndex = 0;
    // find smallest element
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[MinIndex])
            MinIndex = i;

    int Min = arr[MinIndex];
    arr[MinIndex] = arr[n - 1]; // replace it
    n--;
    MaxHeapify(arr, 0, n); // fix heap
    return Min;
}

// increase value of a node
void Heap::IncreaseKey(int arr[], int i, int key) {
    if (arr[i] > key) {
        cout << "key is smaller than current key";
        return;
    }

    arr[i] = key; // set new key

    // move up until heap is valid
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[parent] < arr[i]) {
            Swap(arr[i], arr[parent]);
            i = parent;
        } else break;
    }
}

// insert a new element in heap
void Heap::Insert(int arr[], int key, int &Size) {
    arr[Size] = -99999; // temp small value
    IncreaseKey(arr, Size, key); // set correct value
    Size++; // increase size
}

// increase priority in queue
void Heap::IncreaseKey(int i, int key, int prio) {
    if (priority[i] > prio) {
        cout << "priority is smaller than current priority";
        return;
    }

    pqArr[i] = key;
    priority[i] = prio;

    // bubble up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (priority[parent] < priority[i]) {
            Swap(pqArr[i], pqArr[parent]);
            Swap(priority[i], priority[parent]);
            i = parent;
        } else break;
    }
}

// insert new element in priority queue
void Heap::Insert(int key, int Prio) {
    pqArr[pqSize] = key;
    priority[pqSize] = Prio;
    IncreaseKey(pqSize, key, Prio);
    pqSize++;
}

// remove elements with max priority
void Heap::ExtractMaxP() {
    if (pqSize < 1) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    int maxPriority = priority[0];
    cout << "Values with max priority (" << maxPriority << "): ";

    // remove all with same highest priority
    while (pqSize > 0 && priority[0] == maxPriority) {
        cout << pqArr[0] << " ";
        pqArr[0] = pqArr[pqSize - 1];
        priority[0] = priority[pqSize - 1];
        pqSize--;
        MaxHeapifyP(0); // fix
    }

    cout << endl;
}

// heapify for priority queue
void Heap::MaxHeapifyP(int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < pqSize && priority[left] > priority[largest])
        largest = left;
    if (right < pqSize && priority[right] > priority[largest])
        largest = right;

    if (largest != i) {
        Swap(pqArr[i], pqArr[largest]);
        Swap(priority[i], priority[largest]);
        MaxHeapifyP(largest);
    }
}

// sort array using heap sort
void Heap::SortedArray(int arr[], int &n) {
    int heapSize = n;
    BuildMaxHeap(arr, n); // make heap

    // extract max one by one
    for (int i = heapSize - 1; i >= 0; i--) {
        Sorted[i] = ExtractMax(arr, heapSize);
    }

    // print sorted
    for (int i = 0; i < n; i++)
        cout << Sorted[i] << " ";
}

// build heap from array
void Heap::BuildMaxHeap(int arr[], int Size) {
    for (int i = Size / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, i, Size);
}

// print heap
void Heap::printHeap(int A[]) {
    for (int i = 0; i < Size; i++)
        cout << A[i] << " ";
    cout << endl;
}

// print priority queue
void Heap::printPriorityQueue() {
    if (pqSize == 0) {
        cout << "Priority Queue is empty" << endl;
        return;
    }
    for (int i = 0; i < pqSize; i++)
        cout << "(" << pqArr[i] << ":" << priority[i] << ") ";
    cout << endl;
}

// main function
int main() {
    Heap h;
    int arr[10] = {5, 50, 40, 30, 20, 35};

    h.setSize(6);
    int n = h.getSize();

    cout << "Initial Max Heap:" << endl;
    h.printHeap(arr);

    cout << "After MaxHeapify at root:" << endl;
    h.MaxHeapify(arr, 0, h.getSize());
    h.printHeap(arr);

    cout << "Inserting 45..." << endl;
    h.Insert(arr, 45, n);
    h.setSize(n);
    h.printHeap(arr);

    cout << "Increasing key (20 -> 55)..." << endl;
    h.IncreaseKey(arr, 5, 55);
    h.printHeap(arr);

    cout << "Extracting Max and Min..." << endl;
    int maxVal = h.ExtractMax(arr, n);
    int minVal = h.ExtractMin(arr, n);
    h.setSize(n);
    cout << "Extracted Max = " << maxVal << ", Extracted Min = " << minVal << endl;
    h.printHeap(arr);

    cout << endl << "2- Priority Queue :" << endl;
    h.Insert(10, 2);
    h.Insert(25, 4);
    h.Insert(8, 4);
    h.Insert(20, 5);
    h.Insert(15, 3);

    cout << "Priority Queue after inserts: ";
    h.printPriorityQueue();

    h.IncreaseKey(2, 18, 5);
    cout << "After IncreaseKey (15->18): ";
    h.printPriorityQueue();

    h.ExtractMaxP();
    cout << "Priority Queue after extraction: ";
    h.printPriorityQueue();

    cout << endl << "3- Sort Array :" << endl;
    cout << "Sorted Array :";
    h.SortedArray(arr, n);
    cout << endl;

    return 0;
}
