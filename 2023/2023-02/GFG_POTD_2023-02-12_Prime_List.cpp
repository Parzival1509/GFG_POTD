// GFG POTD 2023/02/12
// Prime List
// Medium

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int num) {
        val = num;
        next = NULL;
    }
};

class Solution {
public:
    bool isPrime(int n) {
        if(n<=1) return false;
        for(int i=2; i<=sqrt(n) ;i++)
            if(n%i==0) return false;
        return true;
    }

    int nearestPrime(int n) {
        if(n <= 1) return 2;
        int i = 0;
        while(true) {
            if(isPrime(n-i)) return n-i;
            if(isPrime(n+i)) return n+i;
            i++;
        }
    }

    Node *primeList(Node *head) {
        Node * p = head;
        while(p) {
            p->val = nearestPrime(p->val);
            p = p->next;
        }
        return head;
    }
};


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Node *head, *tail;
        int num;
        cin>>num;
        head = tail = new Node(num);
        for(int i=0; i<n-1; i++) {
            int num;
            cin>>num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        Solution ob;
        Node *temp = ob.primeList(head);
        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
2 8 6 9
3
2 6 10

Sample Output:
2 7 5 7 
2 5 11 

*/