// GFG POTD 2023/04/12
// Dominant Pairs
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countlower(vector<int> &arr, int s, int e, int val) {
        while(s <= e) {
            int mid = (s+e)/2;
            if(arr[mid]*5 <= val) s = mid+1;
            else e = mid-1;
        }
        return s;
    }
    
    int dominantPairs(int n, vector<int> &arr) {
        int ans = 0;
        sort(arr.begin()+n/2, arr.end());
        for(int i=0; i<n/2; i++)
            ans += countlower(arr, n/2, n-1, arr[i])-n/2;
        return ans;
    } 
};

int main() {
    int T;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin>>i;
        cout<<ob.dominantPairs(n, arr)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
10 2 2 1
6
10 8 2 1 1 2

Sample Output:
2
5

*/