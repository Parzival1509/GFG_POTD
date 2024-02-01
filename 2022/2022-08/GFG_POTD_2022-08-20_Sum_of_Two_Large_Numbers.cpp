//GFG POTD Sum of two Large Numbers
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findSum(string x, string y) {
        int carry=0, len1=x.size()-1, len2=y.size()-1;
        string ans="";
        while(len1>=0 || len2>=0){
            if(len1<0){
                ans.push_back((y[len2]-'0'+carry)%10+48);
                carry = (y[len2]-'0'+carry)/10;
                len2--;
            }
            else if(len2<0){
                ans.push_back((x[len1]-'0'+carry)%10+48);
                carry = (x[len1]-'0'+carry)/10;
                len1--;
            }
            else{
                ans.push_back((x[len1]-'0'+y[len2]-'0'+carry)%10+48);
                carry = (x[len1]-'0'+y[len2]-'0'+carry)/10;
                len1--;
                len2--;
            }
        }
        if(carry){
            ans.push_back('1');
        }
        while(ans.back() == '0')
            ans.pop_back();
        if(ans.size()==0)
            return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }
    return 0;
}

/* Sample Input
1
2500 25

Sample Output
2525

*/