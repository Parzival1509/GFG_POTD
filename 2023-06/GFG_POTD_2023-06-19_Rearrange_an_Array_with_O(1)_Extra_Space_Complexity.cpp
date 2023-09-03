// GFG POTD 2023/06/19
// Rearrange an Array with O(1) Extra Space Complexity
// Medium

#include<bits/stdc++.h>
using namespace std;
    
#define ll long long

class Solution {
public:
    void arrange(ll arr[], int n) {
        for(int i = 0; i < n; i++) {
            ll original = arr[i];
            ll transformed = arr[arr[i]] % n;
            arr[i] = original + transformed * n;
        }
      
        for(int i = 0; i < n; i++)
            arr[i] /= n;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        ob.arrange(A, n);
        for(int i = 0; i < n; i++)
            cout << A[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
2
1 0
5
4 0 2 1 3

Sample Output:
0 1 
3 4 2 0 1 

*/