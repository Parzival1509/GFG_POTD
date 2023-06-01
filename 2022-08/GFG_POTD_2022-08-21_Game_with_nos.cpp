// GFG POTD 2022/08/21
// Game with nos
// Basic

#include<bits/stdc++.h>
using namespace std;

int* game_with_number(int arr[], int n) {
    for(int i=0; i<n-1; i++)
        arr[i] = arr[i]^arr[i+1];
    return arr;
}

int main() {
    int t;
    cin>> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int *arr2;
        arr2 = game_with_number(arr, n);
        for(int i = 0;i < n; i++)
            cout << arr2[i] << " ";
        cout << endl; 
    }
}

/* Sample Input
2
4
5 9 7 6
5
10 11 1 2 3

Sample Output
12 14 1 6 
1 10 3 1 3 

*/