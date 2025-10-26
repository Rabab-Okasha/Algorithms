#include <iostream>

using namespace std;
//task 3

//1-Implement a Heap
class Heap{
private:
int  arr[100];
int Size;
public:
Heap(){
       Size=0;
}
void setSize(int a){
    Size=a;
}
int getSize(){
    return Size;
}
void Insert(int arr[],int key, int& n);
void MaxHeapify(int arr[],int index,int n);
int ExtractMax(int arr[],int& n);
int ExtractMin(int arr[],int & n);
void IncreaseKey (int arr[],int i ,int key);
void printHeap(int A[]);
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
//print
void Heap::printHeap(int A[]){
    for(int i=0; i<Size; i++)
        cout << A[i] << " ";
    cout << endl;
}
int main(){

    Heap h;
  int arr[10] = {5, 50, 40, 30, 20, 35};


    h.setSize(6);

    int n = h.getSize();

    cout << "Initial Max Heap:"<<endl;
    h.printHeap(arr);

cout << "After MaxHeapify at root:" << endl;
h.MaxHeapify(arr, 0, h.getSize());
h.printHeap(arr);

    cout << "Inserting 45..."<<endl;
    h.Insert(arr, 45, n);
    h.setSize(n);
    h.printHeap(arr);

    cout << "Increasing key(20 -> 55)..."<<endl;
    h.IncreaseKey(arr, 5, 55);
    h.printHeap(arr);

    cout << "Extracting Max and Min..."<<endl;
    int maxVal = h.ExtractMax(arr, n);
    int minVal = h.ExtractMin(arr, n);
    h.setSize(n);            // update heap size
    cout << "Extracted Max = " << maxVal<< " Extracted Min = " << minVal<< endl;
    h.printHeap(arr);

   return 0;}
