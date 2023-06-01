// GFG POTD Print the Pattern
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> pattern(int n){
        int k=1;
        string s;
        vector<string> v(n);
        for(int i=1; i<=n; i++){
            s="";
            for(int j=1; j<i; j++)
                s += "--";
            for(int j=i; j<=n; j++){
                s += (to_string(k++)+'*');
            }
            v[i-1] = s;
        }
        
        for(int i=n; i>0; i--){
            s="";
            for(int j=n; j>=i; j--){
                if(j!=i)
                    s += (to_string(k++)+'*');
                else
                    s += to_string(k++);
            }
            v[i-1] += s;
        }
        return v;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans = ob.pattern(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
/* Sample Input

Sample Output

*/