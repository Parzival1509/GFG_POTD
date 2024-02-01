// GFG POTD Lexicographically Smallest String

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPowerOf2(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            if(cnt>=2)
                return false;
            n=n&(n-1);
        }
        if(cnt==1)
            return true;
        return false;
    }
    string lexicographicallySmallest(string S, int k){
        int n=S.size();
        if(isPowerOf2(n))
            k=k/2;
        else
            k=2*k;
      
        if(k>=S.size())
            return "-1";
        
        int m=n-k, cnt=0;
        stack<char> st;
        string temp;
        
        for(int i=0; i<S.size(); i++){  
            while((!st.empty()) && (cnt<k) && (st.top()>S[i])){
                st.pop();
                cnt++;
            }
            st.push(S[i]);
        }
        while(cnt<k){
            st.pop();
            cnt++;
        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

/* Sample Input
2
fooland 2
code 2

Sample Output
and
cde

*/