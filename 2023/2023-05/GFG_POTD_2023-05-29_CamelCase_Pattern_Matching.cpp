// GFG POTD 2023/05/29
// CamelCase Pattern Matching
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> CamelCase(int N, vector<string> dictionary, string pattern) {
        vector<string> ans;
        
        for(auto s: dictionary) {
            bool match = true;
            int i = 0;
            for(auto c: s) {
                if(i == pattern.size()) break;
                
                if(c >= 'A' && c <= 'Z') {
                    if(c != pattern[i]) {
                        match = false;
                        break;
                    }
                    else i++;
                }
            }
            if(i < pattern.size()) match = false;
            if(match) ans.push_back(s);
        }
        
        sort(ans.begin(), ans.end());
        if(ans.size()) return ans;
        
        return {"-1"};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for(int i = 0; i < N; i++)
            cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for(auto u: ans)
            cout << u << "\n";
        cout << "\n";
    }
    return 0;
}

/* Sample Input:
2
3
WelcomeGeek WelcomeToGeeksForGeeks GeeksForGeeks
WTG
8
Hi Hello HelloWorld HiTech HiGeek HiTechWorld HiTechCity HiTechLab
HT

Sample Output:
WelcomeToGeeksForGeeks

HiTech
HiTechCity
HiTechLab
HiTechWorld


*/