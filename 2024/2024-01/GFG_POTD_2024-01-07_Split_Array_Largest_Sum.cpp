// GFG POTD 2024/01/07
// Split Array Largest Sum
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nofmaxsubarray(int arr[], int mid, int N) {
        int count = 1, sum = 0;
        for(int i = 0; i < N; i++) {
            if(sum + arr[i] > mid) {
                count++;
                sum = arr[i];
            }
            else sum += arr[i];
        }
         
        return count;
    }
    
    int splitArray(int arr[], int N, int K) {
        int* max = max_element(arr, arr + N);
        int low = *max, high = 0;
        for( int i = 0; i < N; i++)
            high += arr[i];
        
        int ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            int n = nofmaxsubarray(arr, mid, N);
            
            if(n > K) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N >> K;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.splitArray(arr, N, K) << "\n";
    }

    return 0;
}

/* Sample Input:
2
4 3
1 2 3 4
3 2
1 1 2

Sample Output:
4
2

*/