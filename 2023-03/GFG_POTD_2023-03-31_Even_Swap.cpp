// GFG POTD 2023/03/31
// Even Swap
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallyLargest(vector<int> &arr, int n) {
        for(int i=0; i<n;) {
            int j = i;
            int value = arr[i] & 1;
            while(i < n && (arr[i] & 1) == value) i++;
            if(i-j > 1)
                sort(arr.begin()+j , arr.begin()+i , greater<int>());
        }
        return arr;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &j: a)
            cin>>j;
        Solution s;
        vector<int> b = s.lexicographicallyLargest(a, n);
        for(auto i: b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
1 3 5
4
1 3 4 2

Sample Output:
5 3 1 
3 1 4 2 

*/