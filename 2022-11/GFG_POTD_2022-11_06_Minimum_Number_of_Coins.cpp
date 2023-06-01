// GFG POTD 2022/11/06
// Minimum Number of Coins

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int n){
        vector<int> ans;
        int den[]={2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
            for(int i=0; i<10; i++)
                while(n>=den[i]){
                    ans.push_back(den[i]);
                    n -= den[i];
                }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}

/* Sample Input
4
9 43 1000 3800

Sample Output
5 2 2 
20 20 2 1 
500 500 
2000 500 500 500 200 100 

*/