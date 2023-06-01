// GFG POTD The Bit Game

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int swapBitGame(long long N){
        int count = 0;
        while(N > 0){
            if((N & 1) == 1){
                count++;
            }
            N = N/2;
        }
        return (count%2 == 0)? 2: 1; 
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
}

/* Sample Input
2
8
1

Sample Output
1
1

*/