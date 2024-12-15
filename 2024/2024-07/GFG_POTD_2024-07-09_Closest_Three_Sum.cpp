// GFG POTD 2024/07/09
// Closest Three Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> arr, int target) {
        int diff = INT_MAX, maxi = INT_MIN;
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1, sum = 0;
            while (l < r) {
                sum = arr[i] + arr[l] + arr[r];
                int temp = abs(target - sum);
                if (temp == diff)
                    maxi = max(sum, maxi);
                else if (temp < diff)
                    maxi = sum, diff = temp;

                if (sum < target)
                    l++;
                else r--;
            }
        }

        return maxi;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}

/* Sample Input
2
-7 9 8 3 1 1
2
5 2 7 5
13

Sample Output
2
14

*/