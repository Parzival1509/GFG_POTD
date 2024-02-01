// GFG POTD 2022/10/31
// Satisfy the Equation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> satisfyEqn(int a[], int n) {
        vector<int> ans;
        vector<vector<int>> sums;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(a[i]+a[j]);
                sums.push_back(tmp);
            }
        }
        for(int i=0; i<sums.size()-1; i++){
            for(int j=i+1; j<sums.size(); j++){
                if(sums[i][2]==sums[j][2] && sums[i][0]!=sums[j][0] && sums[i][1]!=sums[j][0]){
                    ans.push_back(sums[i][0]);
                    ans.push_back(sums[i][1]);
                    ans.push_back(sums[j][0]);
                    ans.push_back(sums[j][1]);
                    return ans;
                }
            }
        }
        for(int i=0; i<4; i++)
            ans.push_back(-1);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];
        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}

/* Sample Input
2
7
3 4 7 1 2 9 8
4
424 12 31 7
22
684 931 873 347 748 68 810 604 333 291 68 422 684 39 756 485 215 7 217 690 758 476

Sample Output
0 2 3 5
-1 -1 -1 -1
0 5 10 12

*/