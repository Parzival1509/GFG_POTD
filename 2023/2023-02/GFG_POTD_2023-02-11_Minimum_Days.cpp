// GFG POTD 2023/02/11
// Minimum Days
// Medium

#include<bits/stdc++.h>
using namespace std;

class Array {
public:
    template <class T>
    static void input(vector<T> &A, int n) {
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
    int getMinimumDays(int N, string S, vector<int> &P) {
        int match = 0;
        for(int i = 0; i < N - 1; i++)
            if(S[i] == S[i + 1]) match++;
        
        if(match == 0) return 0;
        for(int day = 0; day < N; day++) {
            int j = P[day];
            if(j + 1 < N and S[j] == S[j + 1]) match--; // reduce match
            if(j >= 0 and S[j - 1] == S[j]) match--;
            S[j] = '?';
            if(!match) return day + 1;
        }
        return 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N, S, P);
        cout<<res<<endl;
    }
}

/* Sample Input:
2
4 aabb
2 1 3 0
4 abca
3 0 2 1

Sample Output:
2
0

*/