// GFG POTD 2023/06/10
// Arranging the Array
// Medium

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    // // Approach 1: Using Extra Space, T.C. = O(N), S.C. = O(N)
    // void Rearrange(int arr[], int n) {
    //     int k = 0;
    //     queue<int> que;
    //     for(int i = 0; i < n; i++)
    //         if(arr[i] < 0) arr[k++] = arr[i];
    //         else que.push(arr[i]);
        
    //     for(int i = k; i < n; i++) {
    //         int val = que.front();
    //         que.pop();
    //         arr[k++] = val;
    //     }
    // }

    // Approach 2: Using Merge Sort, T.C. = O(N log(N)), S.C. = O(log(N))
    void merge(int arr[], int start, int mid, int end) {
        int i = start, j = mid + 1;
        while(i <= mid && arr[i] < 0) i++;
        while(j <= end && arr[j] < 0) j++;
        
        int k = i, l = j - 1, tmp = mid;
        while(i < tmp)
            swap(arr[i++], arr[tmp--]);
            
        tmp = mid + 1;
        j--;
        
        while(tmp < j)
            swap(arr[tmp++], arr[j--]);
        while(k < l)
            swap(arr[k++], arr[l--]);
    }
    
    void mergeSort(int arr[], int start, int end) {
        if(start < end) {
            int mid  = (start + end)/2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }
    
    void Rearrange(int arr[], int n) {
        mergeSort(arr, 0, n - 1);
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        ll j = 0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for(int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 

/* Sample Input:
2
4
-3 3 -2 2
4
-3 1 0 -2

Sample Output:
-3 -2 3 2 
-3 -2 1 0 

*/