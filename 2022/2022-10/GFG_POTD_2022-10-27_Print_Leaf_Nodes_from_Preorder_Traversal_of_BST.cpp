// GFG POTD Print Leaf Nodes From Preorder Traversal of BST

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leafNodes(int arr[], int n) {
        stack<int> st;
        vector<int> nums;
        int j = 1;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[j]){
                st.push(arr[i]);
            }
            else{
                int flag = 0;
                while(!st.empty())
                    if(arr[j] > st.top()){
                        st.pop();
                        flag = 1;
                    }
                    else
                        break;
                
                if(flag)
                    nums.push_back(arr[i]);
            }
            j++;
        }
        nums.push_back(arr[n-1]);
        return nums;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr, N);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
2
2 1
3
3 2 4

Sample Output
1 
2 4 

*/