// GFG POTD Minimum Cost to Cut a Board into Squares
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        int row=1;
        int col=1;
        int i=X.size()-1;
        int j=Y.size()-1;
        int result=0;
        while(i>=0 || j>=0){
            int ans1=i>=0?X[i]:INT_MIN;
            int ans2=j>=0?Y[j]:INT_MIN;
            if(ans1>=ans2){
                result+=ans1*row;
                col++;
                i--;
            }
            else{
                result+=ans2*col;
                row++;
                j--;
            }
        }
        return result;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int>X(m - 1), Y(n - 1);
        for(int i = 0; i < m - 1; i++){
            cin >> X[i];
        }
        for(int i = 0; i < n - 1; i++){
            cin >> Y[i];
        }
        Solution ob;
        int ans = ob.minimumCostOfBreaking(X, Y, m, n);
        cout << ans<<endl;
    }
    return 0;
}