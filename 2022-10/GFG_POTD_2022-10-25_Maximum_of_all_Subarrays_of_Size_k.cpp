// GFG POTD Maximum of all Subarrays of Size k

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> max_of_subarrays(int *arr, int n, int k){
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!dq.empty() and dq.front()==i-k)
                dq.pop_front();
            while(!dq.empty() and arr[dq.back()]<arr[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0;i<n;i++) 
            cin >> arr[i];
        Solution ob;
        vector <int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Sample Output
3 3 4 5 5 5 6 
10 10 10 15 15 90 90 

*/