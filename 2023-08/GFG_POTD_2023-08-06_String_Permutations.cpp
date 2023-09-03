// GFG POTD 2023/08/06
// String Permutations
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string st, int n, int ind, string tmp, vector<string> &ans, vector<int> &hsh) {
        if(ind == n) {
            ans.push_back(tmp);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!hsh[i]) {
                hsh[i] = 1;
                helper(st, n, ind + 1, tmp + st[i], ans, hsh);
                hsh[i] = 0;
            }
        }
    }

    vector<string> permutation(string st) {
        vector<int> hsh(st.size(), 0);
        vector<string> ans;
        helper(st, st.size(), 0, "", ans, hsh);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> vec = ob.permutation(S);
        for(string s: vec)
            cout << s << " ";
        cout << endl << endl;
    }
    return 0;
}

/* Sample Input:
5
AAA
ABC
ABSG
ZSKU
PRJJX

Sample Output:
AAA AAA AAA AAA AAA AAA 

ABC ACB BAC BCA CAB CBA 

ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA 

KSUZ KSZU KUSZ KUZS KZSU KZUS SKUZ SKZU SUKZ SUZK SZKU SZUK UKSZ UKZS USKZ USZK UZKS UZSK ZKSU ZKUS ZSKU ZSUK ZUKS ZUSK 

JJPRX JJPRX JJPXR JJPXR JJRPX JJRPX JJRXP JJRXP JJXPR JJXPR JJXRP JJXRP JPJRX JPJRX JPJXR JPJXR JPRJX JPRJX JPRXJ JPRXJ JPXJR JPXJR JPXRJ JPXRJ JRJPX JRJPX JRJXP JRJXP JRPJX JRPJX JRPXJ JRPXJ JRXJP JRXJP JRXPJ JRXPJ JXJPR JXJPR JXJRP JXJRP JXPJR JXPJR JXPRJ JXPRJ JXRJP JXRJP JXRPJ JXRPJ PJJRX PJJRX PJJXR PJJXR PJRJX PJRJX PJRXJ PJRXJ PJXJR PJXJR PJXRJ PJXRJ PRJJX PRJJX PRJXJ PRJXJ PRXJJ PRXJJ PXJJR PXJJR PXJRJ PXJRJ PXRJJ PXRJJ RJJPX RJJPX RJJXP RJJXP RJPJX RJPJX RJPXJ RJPXJ RJXJP RJXJP RJXPJ RJXPJ RPJJX RPJJX RPJXJ RPJXJ RPXJJ RPXJJ RXJJP RXJJP RXJPJ RXJPJ RXPJJ RXPJJ XJJPR XJJPR XJJRP XJJRP XJPJR XJPJR XJPRJ XJPRJ XJRJP XJRJP XJRPJ XJRPJ XPJJR XPJJR XPJRJ XPJRJ XPRJJ XPRJJ XRJJP XRJJP XRJPJ XRJPJ XRPJJ XRPJJ 


*/