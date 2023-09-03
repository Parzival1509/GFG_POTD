// GFG POTD 2023/07/13
// Unique Number of Occurences
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++)
            freq[arr[i]]++;
            
        unordered_set<int> ct;
        for(auto i: freq)
            ct.insert(i.second);
            
        if(freq.size() == ct.size())
            return true;
        return false;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout << ob.isFrequencyUnique(n, arr) << endl;
    }
}

/* Sample Input:
2
5
1 1 2 5 5
10
2 2 5 10 1 2 10 5 10 2

Sample Output:
0
1

*/