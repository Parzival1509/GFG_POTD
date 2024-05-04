// GFG POTD 2024/04/11
// Gray to Binary Equivalent
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int grayToBinary(int n) {
        if (n == 0)
            return 0;

        string bin = "";
        while (n) {
            bin += to_string(n % 2);
            n /= 2;
        }

        reverse(bin.begin(), bin.end());
        string gray = "";
        gray.push_back(bin[0]);
        for (int i = 1; i < bin.size(); i++) {
            int idea = (bin[i] - '0') ^ (gray.back() - '0');
            gray += to_string(idea);
        }
        
        return stoi(gray, 0, 2);
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        Solution ob;
        cout << ob.grayToBinary(n) << endl;
    }
}

/* Sample Input
2
4
15

Sample Output
7
10

*/