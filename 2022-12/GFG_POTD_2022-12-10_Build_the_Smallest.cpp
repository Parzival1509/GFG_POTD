// GFG POTD 2022/12/10
// Build the Smallest
// Medium

#include<bits/stdc++.h>
using namespace std;

string buildLowestNumber(string num, int k) {
    int n=num.size();
    stack<char> s;
    s.push(num[0]);
    for(int i=1; i<n; i++) {
        while(!s.empty() && s.top()>num[i] && k>0) {
            s.pop();
            --k;
        }
        s.push(num[i]);
    }

    while(k--)
        s.pop();

    string res="";
    while(!s.empty()) {
        res = s.top() + res;
        s.pop();
    }
    
    int ind=-1;
    for(int i=0; i<res.size(); i++) {
        if(res[i]!='0')
            break;
        ind=i;
    }
    if(ind==res.size()-1)
        return "0";
    return res.substr(ind+1);
}

int main() {
    int t,n;
    string str;
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>str;
        cout << buildLowestNumber(str, n) << endl;
    }
    return 0;
}

/* Sample Input
2
2 143729
3 10056

Sample Output
1329
0

*/