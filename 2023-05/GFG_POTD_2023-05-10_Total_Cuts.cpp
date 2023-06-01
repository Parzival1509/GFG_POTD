// GFG POTD 2023/05/10
// Total Cuts
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalCuts(int n, int k, vector<int> &arr) {
        vector<int> maxL(n), minR(n);
        maxL[0] = arr[0], minR[n-1] = arr[n-1];
        
        // Storing max elements from left
        for(int i=1; i<n; i++) {
            if(maxL[i-1] < arr[i]) maxL[i] = arr[i];
            else maxL[i] = maxL[i-1];
        }
        
        // Storing min elements from right
        for(int i=n-2; i>=0; i--) {
            if(minR[i+1] > arr[i]) minR[i] = arr[i];
            else minR[i] = minR[i+1];
        }

        int cuts = 0;
        for(int i=0; i<n-1; i++) {
            if(maxL[i] + minR[i+1] >= k) cuts++;
        }

        return cuts;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.totalCuts(n, k, arr)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 3
1 2 3
5 5
1 2 3 4 5

Sample Output:
2
3

*/