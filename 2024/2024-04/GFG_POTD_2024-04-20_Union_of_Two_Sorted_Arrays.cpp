// GFG POTD 2024/04/20
// Union of Two Sorted Arrays
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(arr1[i]);
        for (int i = 0; i < m; i++)
            st.insert(arr2[i]);
        
        vector<int> ans;
        for (auto it : st)
            ans.push_back(it);
        
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        int arr1[N], arr2[M];
        for (int i = 0; i < N; i++)
            cin >> arr1[i];
        for (int i = 0; i < M; i++)
            cin >> arr2[i];
        
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}

/* Sample Input
3
5 5
1 2 3 4 5
1 2 3 6 7
5 5
2 2 3 4 5
1 1 2 3 4
5 5
1 1 1 1 1
2 2 2 2 2

Sample Output
1 2 3 4 5 6 7 
1 2 3 4 5 
1 2 

*/