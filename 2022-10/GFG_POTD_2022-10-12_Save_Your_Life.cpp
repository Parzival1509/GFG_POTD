// GFG POTD Save Your Life
// Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string maxSum(string w,char x[], int b[],int n){
        unordered_map<char ,int> m;
        for(int i=0;i<n;++i)
                m[x[i]] = b[i];
        // for(auto el:m)cout<<el.first<<" "<<el.second<<endl;
        long long currsum = 0, maxsum = INT_MIN;
        int p =0, q =0 , t=0;
        for(int i=0;i<w.size();++i){
            if(m[w[i]] != 0){
                // cout<<"yo";
                currsum += m[w[i]];
            }
            else
                currsum += (int)w[i];
                // cout<<currsum<<endl;
            if(currsum >= maxsum){
                maxsum = currsum;
                q = i;
                if(t<=q)
                    p = t;
            }  
            if(currsum < 0){
                currsum = 0 ;
                // if(q>0)
                t = i+1 ;
            }
        }
        string ans ;
        for(int i=p;i<=q ;++i)
        ans.push_back(w[i]);
        return ans ;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}

/* Sample Input
2
abcde
1
c
-1000
dbfbsdbf
2
b s
-100 45

Sample Output
de
dbfbsdbf

*/