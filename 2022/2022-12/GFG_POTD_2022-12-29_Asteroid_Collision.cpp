// GFG POTD 2022/12/29
// Asteroid Collision
// Medium

#include <bits/stdc++.h>
using namespace std;

// My Sol
class Solution {
public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        stack<int> st;
        
        for(int i=0; i<n; i++) {
        	if(st.empty()) st.push(asteroids[i]);		// if st is empty, push
        	else if(st.top()*asteroids[i] > 0) st.push(asteroids[i]);	// if both are of same sign, push
        	else if(st.top() < 0) st.push(asteroids[i]);	// if top element is -ve, push again
        	else {										// if top of st is +ve
        		if(st.top() + asteroids[i] == 0)		// both of same size
        			st.pop();
        		else if(st.top() + asteroids[i] > 0)	// top of stack is bigger in size
        			continue;
        		else {								// top of stack is smaller in size
        			while(!st.empty() && st.top() > 0 && st.top() + asteroids[i] < 0)
        				st.pop();
        			if(!st.empty() && st.top() + asteroids[i] == 0)
        				st.pop();
        			else if(st.empty() || st.top() < 0)
        				st.push(asteroids[i]);
        		}
        	}
        }

        vector<int> ans;
        while(!st.empty()) {
        	ans.push_back(st.top());
        	st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        vector<int> asteroids(N);
        for(int i=0; i<N; i++)
        	cin >> asteroids[i];
        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for(auto &it: ans)
        	cout << it << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input
6
3
2 -2 2
3
3 5 -3
2
-5 5
6
-5 5 2 1 1 -2
6
1 -7 -3 -12 1 -8
9
6 -10 16 -10 3 -15 3 -1 16

Sample Output
2 
3 5 
-5 5 
-5 5 
-7 -3 -12 -8 
-10 16 3 16 

*/