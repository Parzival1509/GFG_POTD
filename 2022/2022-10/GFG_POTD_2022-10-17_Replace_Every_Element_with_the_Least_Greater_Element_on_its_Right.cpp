// GFG POTD Replace Every Element with Least Greater Element on its Right

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> nums;
        set<int> st;
        for(int i=n-1;i>=0;i--){
            st.insert(arr[i]);
            auto it = st.find(arr[i]);
            if((++it) != st.end()){
                nums.push_back(*it);
            }
            else{
                nums.push_back(-1);
            }
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for(auto it : ans){
            cout << it << " ";
        }
        cout <<endl;
    }
    return 0;
}

/* Sample Input
2
15
8 5 71 18 31 32 63 92 43 3 91 93 225 80 28
6
2 6 9 1 3 2

Sample Output
18 18 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 
3 9 -1 2 -1 -1 

*/