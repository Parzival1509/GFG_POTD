// GFG POTD 2023/07/06
// Quick Sort
// Medium

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

class Solution {
public:
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
    
    int partition (int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
    
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};

int main() {
    int arr[1000], n, T, i;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        ob.quickSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}

/* Sample Input:
2
5
4 1 3 9 7
9
2 1 6 10 4 1 3 9 7

Sample Output:
1 3 4 7 9 
1 1 2 3 4 6 7 9 10 

*/