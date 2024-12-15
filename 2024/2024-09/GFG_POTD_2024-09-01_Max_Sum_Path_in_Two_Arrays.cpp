// GFG POTD 2024/09/01
// Max Sum Path in Two Arrays
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathSum(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        long long ans = 0, sum1 = 0, sum2 = 0;

        while (i >= 0 && j >= 0) {
            if (arr1[i] > arr2[j])
                sum1 += arr1[i--];
            else if (arr1[i] < arr2[j])
                sum2 += arr2[j--];
            else {
                ans += max(sum1 + arr1[i--], sum2 + arr2[j--]);
                sum1 = sum2 = 0;
            }
        }

        while (i >= 0)
            sum1 += arr1[i--];
        while (j >= 0)
            sum2 += arr2[j--];

        ans += max(sum1, sum2);

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
            arr1.push_back(number);

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
            arr2.push_back(number2);

        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}

/* Sample Input
3
2 3 7 10 12
1 5 7 8
1 2 3
3 4 5
1 2 5 8 10
1 2 3 5 9

Sample Output
35
15
29

*/