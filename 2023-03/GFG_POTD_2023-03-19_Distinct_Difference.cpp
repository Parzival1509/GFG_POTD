// GFG POTD 2023/03/19
// Distinct Difference
// Easy

#include<bits/stdc++.h>
using namespace std;

class Array {
public:
    template <class T>
    static void input(vector<T> &A,int n) {
        for (int i = 0; i < n; i++)
            scanf("%d ",&A[i]);
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

class Solution {
public:
    vector<int> getDistinctDifference(int n, vector<int> &a) {
        unordered_set<int> left, right;
        vector<int> lv(n), rv(n), ans(n);
        
        lv[0] = 0;
        for(int i=1; i<n; i++) {
            left.insert(a[i-1]);
            lv[i] = left.size();
        }
        
        rv[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            right.insert(a[i+1]);
            rv[i] = right.size();
        }
        
        for(int i=0; i<n; i++)
            ans[i] = lv[i] - rv[i];
        
        return ans;
    }
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        int N;
        scanf("%d",&N);
        vector<int> A(N);
        Array::input(A,N);
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        Array::print(res);
    }
}

/* Sample Input:
2
3
4 3 3
4
4 4 3 3

Sample Output:
-1 0 2 
-2 0 0 2 

*/