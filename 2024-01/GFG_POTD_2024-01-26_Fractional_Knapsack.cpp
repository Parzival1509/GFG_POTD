// GFG POTD 2024/01/26
// Fractional Knapsack
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool cmp(Item a, Item b)  {
        return ((double) a.value / a.weight) > ((double) b.value / b.weight);   
    }

    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, cmp);
        double maxP = 0, currWt = 0;
        
        for(int i = 0; i < n; i++) 
            if(currWt + arr[i].weight <= w)  {
                maxP += arr[i].value;
                currWt += arr[i].weight;
            }
            else {
                maxP += double((arr[i].value * (w - currWt)) / arr[i].weight);
                break;
            }
        
        return maxP;
    } 
};

int main() {
    int t;
    cin >> t;
    cout << setprecision(6) << fixed;
    while(t--) {
        int n, W;
        cin >> n >> W;
        
        Item arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i].value >> arr[i].weight;
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }

    return 0;
}

/* Sample Input:
2
3 50
60 10 100
20 120 30
2 50
60 100
10 20

Sample Output:
240.000000
30.000000

*/