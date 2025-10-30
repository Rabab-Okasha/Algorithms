#include <iostream>
using namespace std;
//task 1 fibonannci

int Recursion(int n) {
    if (n==0) {
        return 0;
    }
    if (n==1 || n==2) {
        return 1;
    }
    return Recursion(n-1) + Recursion(n-2);
}

int divideAndConquer(int n) {
    if (n==0) {
        return 0;
    }
    if (n==1 || n==2) {
        return 1;
    }
    for (int i = 0; i <= n; i++) {}
}
int main() {

    // int n;
    // cin>>n;
    // cout<<Recursion(n);

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.