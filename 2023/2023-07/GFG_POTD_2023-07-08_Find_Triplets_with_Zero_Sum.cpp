// GFG POTD 2023/07/08
// Find Triplets with Zero Sum
// Basic

#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool findTriplets(int arr[], int n) { 
        sort(arr, arr + n);
        for(int i = 0; i < n - 2; i++) {
            int start = i + 1, end = n - 1;
            while (start < end) {
                int sum = arr[i] + arr[start] + arr[end];

                if(sum == 0) return 1;
                if(sum > 0) end--;
                else start++;
            }
        }
        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n] = {0};
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.findTriplets(arr, n) << endl;
    }
    return 0;
}

/* Sample Input:
2
5
0 -1 -2 -3 1
3
1 2 3

Sample Output:
1
0

*/