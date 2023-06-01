// GFG POTD 2022/11/27
// Add Binary Strings

#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    string addBinary(string a, string b) {
        string res;
        int i=a.length()-1, j=b.length()-1, carry=0;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0)
                sum += a[i--] - '0';
            if(j>=0)
                sum += b[j--] - '0';
            carry = sum>1? 1: 0;
            res += to_string(sum % 2);
        }
        if(carry)
            res += to_string(carry);
        reverse(res.begin(), res.end());
        i = 0;
        while(res[i]=='0')
            res.erase(0, 1);
        return res;
    }
};

int main(){
    int t; cin >> t;
    while (t--){
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary (A, B) << endl;
    }
}

/* Sample Input
2
10 01
1101 111

Sample Output
11
10100

*/