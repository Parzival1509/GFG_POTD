// GFG POTD 2023/01/24
// Convert an Array to Reduced Form
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    
    void convert(int arr[], int n) {
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++)
            v[i] = {arr[i], i};
        sort(v.begin(), v.end(), cmp);

        for(int i=0; i<n; i++)
            arr[v[i].second] = i;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        ob.convert(arr, n);
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
3
10 40 20
5
5 10 40 30 20

Sample Output
0 2 1 
0 1 4 3 2 

*/