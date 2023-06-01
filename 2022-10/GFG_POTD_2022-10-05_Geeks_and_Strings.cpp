// GFG POTD Geek and Strings

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string qr[]){
        unordered_map<string,int>M;
        for(int i=0;i<Q;i++){
            M[qr[i]]=0;
        }
        for(int i=0;i<N;i++){
            string s=li[i];
            string t="";
            for(int j=0;j<s.size();j++){
                t.push_back(s[j]);
                if(M.find(t)!=M.end())
                    M[t]++;
            }
        }
        vector<int>count;
        for(int i=0;i<Q;i++)
            count.push_back(M[qr[i]]);
        return count;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
        cin>>N;
        string s;
        string li[N];
        for(int i = 0;i < N;i++)
            cin>>li[i];
        cin>>Q; 
        x = Q;
        string query[Q];
        while(Q--){
            cin>>s;
            query[i++] = s;
        }
        
        Solution ob;
        vector<int> ans = ob.prefixCount(N, x, li, query);
        for(auto i: ans) 
            cout<<i<<"\n";
    }
    return 0;
}

/* Sample Input
1
5
abracadabra geeks geeksforgeeks abracadabra geeksbest
5
abr geeks geeksforgeeks ge gar

Sample Output
2
3
1
3
0

*/