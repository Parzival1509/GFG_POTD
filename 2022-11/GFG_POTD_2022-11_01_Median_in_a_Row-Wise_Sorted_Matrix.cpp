// GFG POTD 2022/11/01
// Median in a row-wise sorted Matrix

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(vector<int>&A,int val){
        int low=0;
        int high=A.size()-1;
        while(low<=high){
            int mid=low +(high-low)/2;
            if(A[mid]<=val)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=1;
        int high=2001;
        int actual_count=(R*C-1)/2;
        while(low<=high){
            int mid=low + (high-low)/2;
            int count=0;
            for(int i=0;i<R;i++){
                count += solve(matrix[i],mid);
            }
            if(count<=actual_count)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}

/* Sample Input
2
3 3
1 3 5
2 6 9
3 6 9
3 1
1 2 3

Sample Output
5
2

*/