#include <iostream>
using namespace std;
//task 1 fibonannci

int Recursion(int n) {
    if (n==0) { //base case
        return 0;
    }
    if (n==1) { //base case
        return 1;
    }
    return Recursion(n-1) + Recursion(n-2); // Recursive formula: F(n) = F(n-1) + F(n-2)
}
//multiply two matrixes and store the result
void multiply(int A[2][2], int B[2][2] , int result[2][2]) {
    result[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    result[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    result[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    result[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
}
void power(int m[2][2], int n) {
    if (n==0 || n==1) { //base case
        return;
    }
    int matrix[2][2] ={{1,1},{1,0}}; //base matrix

    power(m,n/2);

    int result[2][2];
    multiply(m,m,result);

    //these store the value of result matrix
    m[0][0] = result[0][0];
    m[0][1] = result[0][1];
    m[1][0] = result[1][0];
    m[1][1] = result[1][1];

    //if the power is odd then multiply the result with the base matrix
    if ((n%2)!=0) {
        multiply(m,matrix,result);
        m[0][0] = result[0][0];
        m[0][1] = result[0][1];
        m[1][0] = result[1][0];
        m[1][1] = result[1][1];
    }
}
void DivideAndConquer(int n) {
    int F[2][2] = {{1,1},{1,0}};
    power(F, n);
    cout << "Fibonacci(" << n << ") = " << F[0][1] << endl;

}
int Dynamic(int n) {
    int array[n];
    array[0] = 0; //base case
    if (n>0) {
        array[1]=1; //base case
        for (int i=2; i<=n; i++) { //fill array using fibonnanci formula
            array[i]=array[i-1]+array[i-2];
        }
    }
    return array[n];
}
int main() {

    cout<<"Enter the number to get its fibonanci "<<endl;
    int n;
    cin>>n;
    cout<<"choose the method: (1)recurrence (2)divide and conquer (3)dynamic programming "<<endl;
    int choice;
    cin>>choice;
    switch(choice) {
        case 1:
            cout<<"Fibonacci(" << n << ") = "<<Recursion(n)<<endl;
        break;
        case 2:
            DivideAndConquer(n);
        break;
        case 3:
            cout<<"Fibonacci(" << n << ") = "<<Dynamic(n)<<endl;
        break;
        default:
            cout<<"Wrong choice"<<endl;
    }


    return 0;
}

