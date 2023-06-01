// GFG POTD 2023/01/12
// Minimize the Sum
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        int sum = 0;
        multiset<int>st;
        for(auto i: arr) st.insert(i);
        
        while(!st.empty()) {
            if(st.size() == 1) break;
            int a = *st.begin();
            st.erase(st.begin());
            int b = *st.begin();
            st.erase(st.begin());
            sum += a+b;
            st.insert(a+b);
        }
        return sum;
    }
};

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}

/* Sample Input
2
4
1 4 7 10
5
1 3 7 5 6

Sample Output
39
48

*/