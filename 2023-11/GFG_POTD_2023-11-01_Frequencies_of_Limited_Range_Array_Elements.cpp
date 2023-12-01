// GFG POTD 2023/11/01
// Frequencies of Limited Range Array Elements
// Easy

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void frequencyCount(vector<int>& arr, int n, int p) { 
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                int tmp = arr[i];
                arr[i] = -1;
                
                while(tmp > 0 && tmp <= n) {
                    int t = arr[tmp - 1];
                    if(arr[tmp - 1] > 0)
                        arr[tmp - 1] = -1;
                    arr[tmp - 1]--;
                    tmp = t;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            arr[i]++;
            arr[i] *= -1;
        }
    }
};

int main() {
    long long t;
    cin >> t;
    while(t--) {
        int N, P;
        cin >> N >> P;
        vector<int> arr(N);
        for(int i = 0; i < N ; i++)
            cin >> arr[i]; 
        Solution ob;
        ob.frequencyCount(arr, N, P); 
        
        for(int i = 0; i < N ; i++) 
            cout << arr[i] << " ";
        cout << endl;
    }   
    return 0; 
}

/* Sample Input:
3
5 5
2 3 2 3 5
4 3
3 3 3 3
2 9
8 9

Sample Output:
0 2 2 0 1 
0 0 4 0 
0 0 

*/