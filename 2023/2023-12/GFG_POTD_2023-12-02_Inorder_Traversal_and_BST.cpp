// GFG POTD 2023/12/02
// Inorder Traversal and BST
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isRepresentingBST(int arr[], int n) {
        for(int i = 0; i < n - 1; i++)
            if(arr[i] > arr[i + 1])
                return 0;
                
        return 1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.isRepresentingBST(arr, N) << endl;
    }

    return 0;
}

/* Sample Input:
2
3
2 4 5
3
2 4 1

Sample Output:
1
0

*/