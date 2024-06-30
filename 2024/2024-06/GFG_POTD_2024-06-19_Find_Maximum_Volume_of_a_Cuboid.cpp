// GFG POTD 2024/06/19
// Find Maximum Volume of a Cuboid
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxVolume(double perimeter, double area) {
        double h = (perimeter - sqrt(perimeter * perimeter - 24 * area)) / 12;
        double l = (perimeter / 4 - 2 * h);
        return h * h * l;
    }
};

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}

/* Sample Input
2
22 15
20 5

Sample Output
3.02
0.33

*/