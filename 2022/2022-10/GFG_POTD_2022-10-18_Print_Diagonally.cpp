// GFG POTD Print Diagonally

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> downwardDigonal(int n, vector<vector<int>> a){
        vector<int> ans(n*n);
        int m=0, k, i, j;
        for(k=0; k<n; k++){
            i=0;
            j=k;
            while(j>=0)
                ans[m++]=a[i++][j--];
        }
        for(k=1; k<n; k++){
            i=k;
            j=n-1;
            while(i<n)
                ans[m++]=a[i++][j--];
        }
        return ans;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> A(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
2
1 2
3 4
3
1 2 4
3 5 7
6 8 9

Sample Output
1 2 3 4 
1 2 3 4 5 6 7 8 9 

*/