// GFG POTD 2023/01/08
// Absolute Difference Divisible by K
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(int n, int arr[], int k) {
        unordered_map<int,int> map;     
        int res=0;
        for(int i=0; i<n; ++i) {
            if(map.find(arr[i]%k) != map.end())
                res += map[arr[i]%k];
            map[arr[i]%k]++; 
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}

/* Sample Input
2
3
3 7 11
4
4
1 2 3 4
2

Sample Output
3 
2 

*/