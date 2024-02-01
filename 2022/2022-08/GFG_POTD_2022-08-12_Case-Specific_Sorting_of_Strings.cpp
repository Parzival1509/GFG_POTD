#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution{
public:
    string caseSort(string str, int n)
    {
        vector<char> ml, mu;
        vector<int> nl, nu;
        for(int i=0; i<n; i++){
            if(str[i] <= 'Z'){
                nu.push_back(i);
                mu.push_back(str[i]);
            }
            else{
                nl.push_back(i);
                ml.push_back(str[i]);
            }
        }
        sort(mu.begin(), mu.end());
        sort(ml.begin(), ml.end());
        for(int i=0; i<nl.size(); i++){
            str[nl[i]] = ml[i];
        }
        for(int i=0; i<nu.size(); i++){
            str[nu[i]] = mu[i];
        }
        return str;
    }
};

int main(){
    Solution ob;
    string s;
    cin>>s;
    cout<<ob.caseSort(s, s.size());
    return 0;
}

/* Sample Input
defRTSersUXI

Sample Output
deeIRSfrsTUX
*/