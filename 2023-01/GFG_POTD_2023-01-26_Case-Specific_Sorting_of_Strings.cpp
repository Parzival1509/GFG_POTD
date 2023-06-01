// GFG POTD 2023/01/26
// Case-Specific Sorting of Strings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string caseSort(string str, int n) {
        vector<char> ml, mu;
        vector<int> nl, nu;
        for(int i=0; i<n; i++) {
            if(str[i] <= 'Z') {
                nu.push_back(i);
                mu.push_back(str[i]);
            }
            else {
                nl.push_back(i);
                ml.push_back(str[i]);
            }
        }
        sort(mu.begin(), mu.end());
        sort(ml.begin(), ml.end());
        for(int i=0; i<nl.size(); i++)
            str[nl[i]] = ml[i];
        for(int i=0; i<nu.size(); i++)
            str[nu[i]] = mu[i];
        return str;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string str;
        cin>>str;
        Solution obj;
        cout<<obj.caseSort(str, n)<<endl;
    }
}

/* Sample Input
2
12
defRTSersUXI
6
srbDKi

Sample Output
deeIRSfrsTUX
birDKs

*/