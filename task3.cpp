#include <iostream>

using namespace std;
//task 3

//1-Implement a Heap
class Heap{
private:
int priority[100];//for queue
int pqArr[100];
int pqSize;
int  arr[100];
int Size;
public:
Heap(){
       Size=0;
       pqSize=0;
}
void setSize(int a){
    Size=a;
}
int getSize(){
    return Size;
}
int getPriority(int i) { return priority[i]; }

void Insert(int arr[],int key, int& n);
void MaxHeapify(int arr[],int index,int n);
int ExtractMax(int arr[],int& n);
int ExtractMin(int arr[],int & n);
void IncreaseKey (int arr[],int i ,int key);
void printHeap(int A[]);
void BuildMaxHeap(int arr[], int Size);
//2- Priority Queue
void IncreaseKey (int i ,int key, int Priority);
void ExtractMaxP();
void Insert(int key,int Priority );
void MaxHeapifyP(int i);
void printPriorityQueue();
};

//swap for heapify
void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

// heapify function (max heapify)
void Heap::MaxHeapify(int arr[],int i,int Size){
    int left =(2*i)+1;
    int right =(2*i)+2;
    int largest =i;
    if(left<Size && arr[left]>arr[largest]){
        largest=left;
    }
    if (right<Size && arr[right]>arr[largest]){
        largest=right;}
    if(largest!=i){
        Swap(arr[i],arr[largest]);
         MaxHeapify(arr,largest,Size);
    }

}

//extract max
int Heap::ExtractMax(int arr[], int &n) {

    if (n < 1) {
        cout << "Heap is empty" << endl;
        return -1;
    }
    int Max = arr[0];
    arr[0] = arr[n - 1];
    n--;
    MaxHeapify(arr, 0, n);

    return Max ;
}


//extract min

int Heap::ExtractMin(int arr[], int &n) {
    if (n < 1) {
        cout << "Heap is empty" << endl;
        return -1;
    }
    int MinIndex = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[MinIndex])
            MinIndex = i;

    int Min = arr[MinIndex];
    arr[MinIndex] = arr[n - 1];
    n--;
    MaxHeapify(arr, 0, n);
    return Min;
}


//i will use it in insert
void Heap:: IncreaseKey (int arr[],int i ,int key){

if (arr[i]>key){
    cout<< "key is smaller than current key";
    return ;
}
arr[i]=key;
while(i>0){
         int parent=(i-1)/2;
        if(arr[parent]< arr[i]){
    Swap(arr[i],arr[parent]);
    i=parent;
    }
    else{
        break;
    }
}
}


//insert
void Heap::Insert(int arr[],int key, int &Size){
arr[Size] = -99999;
IncreaseKey(arr,Size,key);
Size++;
}
 //queue
 void Heap::IncreaseKey(int i ,int key,int prio){

     if (priority[i]>prio){
    cout<< "priority is smaller than current priority";
    return ;
}
pqArr[i]=key;
priority[i]=prio;
while(i>0){
         int parent=(i-1)/2;
        if(priority[parent]< priority[i]){
    Swap(pqArr[i],pqArr[parent]);
    Swap(priority[i],priority[parent]);
    i=parent;
    }
    else{
        break;
    }
}
 }

 void Heap::Insert(int key, int Prio) {
    pqArr[pqSize] = key;
    priority[pqSize] = Prio;
    IncreaseKey(pqSize, key, Prio);
    pqSize++;
}

void Heap::ExtractMaxP() {
    if (pqSize < 1) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    int maxPriority = priority[0];
    cout << "Values with max priority (" << maxPriority << "): ";

    while (pqSize > 0 && priority[0] == maxPriority) {
        cout << pqArr[0] << " ";
        pqArr[0] = pqArr[pqSize - 1];
        priority[0] = priority[pqSize - 1];
        pqSize--;
        MaxHeapifyP(0);
    }

    cout << endl;
}


void Heap::MaxHeapifyP(int i) {
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < pqSize && priority[left] > priority[largest])
        {largest = left;}
    if (right < pqSize && priority[right] > priority[largest])
        {largest = right;}

    if (largest != i) {
        Swap(pqArr[i], pqArr[largest]);
        Swap(priority[i], priority[largest]);
        MaxHeapifyP(largest);
    }
}



//build max heap
void Heap::BuildMaxHeap(int arr[], int Size){
for(int i=Size/2-1;i>=0;i--){
    MaxHeapify(arr,i,Size);
}
}

//print
void Heap::printHeap(int A[]){
    for(int i=0; i<Size; i++)
        cout << A[i] << " ";
    cout << endl;
}
// queue
void Heap:: printPriorityQueue() {
    if (pqSize == 0) {
        cout << "Priority Queue is empty" << endl;
        return;
    }
    for (int i = 0; i < pqSize; i++) {
        cout << "(" <<pqArr[i] << ":" << priority[i] << ") ";
    }
    cout << endl;
}

int main(){

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
cout<<endl;
    cout << "2- Priority Queue :" << endl;
h.Insert(10, 2);
h.Insert(20, 5);
h.Insert(15, 3);
h.Insert(25, 4);
h.Insert(8, 4);
cout << "Priority Queue after inserts: ";
h.printPriorityQueue();
h.IncreaseKey(2, 18, 5);
cout << "After IncreaseKey (15->18): ";
h.printPriorityQueue();
 h.ExtractMaxP();
cout << "Priority Queue after extraction: ";
h.printPriorityQueue();
return 0;
}
