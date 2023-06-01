// GFG POTD 2023/05/12
// Array Operations
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayOperations(int n, vector<int> &arr) {
        bool f = false;
        int cntZero = count(arr.begin(), arr.end(), 0);
        if(cntZero == 0) return -1;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if( f == false && arr[i] != 0) {
                cnt++;
                f = true;
            }
            else if( arr[i] == 0) f = false;
        }
        return cnt;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        cout<<res<<endl;
    }
}

/* Sample Input:
2
4
3 0 4 5
8
10 4 9 6 10 10 4 4

Sample Output:
2
-1

*/