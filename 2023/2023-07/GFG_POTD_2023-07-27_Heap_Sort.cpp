// GFG POTD 2023/07/27
// Heap Sort
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
      
        if(l < n && arr[largest] < arr[l]) largest = l;
        if(r < n && arr[largest] < arr[r]) largest = r;
      
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n) {
        for(int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {
        buildHeap(arr, n);
        for(int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        Solution ob;
        ob.heapSort(arr, n);

        for(int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Sample Output:
1 3 4 7 9 
1 2 3 4 5 6 7 8 9 10 

*/