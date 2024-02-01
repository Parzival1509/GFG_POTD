// GFG POTD 2023/06/13
// K Largest Elements
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n--) {
            pq.push(arr[n]);
            if(pq.size() > k)
                pq.pop();
        }
    
        vector<int> res(k);
        while(k--) {
            res[k] = pq.top();
            pq.pop();
        }
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for(auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input:
2
5 2
12 5 787 1 23
7 3
1 23 12 9 30 2 50

Sample Output:
787 23 
50 30 23 

*/