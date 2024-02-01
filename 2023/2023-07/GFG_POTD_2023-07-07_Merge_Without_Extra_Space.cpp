// GFG POTD 2023/07/07
// Merge Without Extra Space
// Hard

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        int i = n - 1, j = 0;
        while(i >= 0 && j < m && arr1[i] > arr2[j])
            swap(arr1[i--], arr2[j++]);
        
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];
        for(int i = 0; i < n; i++)
            cin >> arr1[i];
        for(int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        ob.merge(arr1, arr2, n, m); 
        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" ";
        cout << endl;

        for (int i = 0; i < m; i++) 
            cout<<arr2[i]<<" ";
        cout << endl;

        cout << endl;
    }

    return 0; 
}

/* Sample Input:
2
4 5
1 3 5 7
0 2 6 8 9
2 3
10 12
5 18 20

Sample Output:
0 1 2 3 
5 6 7 8 9 

5 10 
12 18 20 


*/