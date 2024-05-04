// GFG POTD 2024/04/30
// Add Two Numbers Represented by Linked Lists
// Medium

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size) {
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;

        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
        Node* rnum1 = reverse(num1);
        Node* rnum2 = reverse(num2);

        Node* ans = new Node(-1);
        Node* temp1 = rnum1;
        Node* temp2 = rnum2;
        Node* anstemp = ans;
        int sum = 0, carry = 0;

        while (temp1 || temp2 || carry) {
            sum = 0;
            if (temp1) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2) {
                sum += temp2->data;
                temp2 = temp2->next;
            }

            sum += carry;
            carry = sum / 10;
            anstemp->next = new Node(sum % 10);
            anstemp = anstemp->next;
        }

        ans = reverse(ans->next);
        while (ans->data == 0 && ans->next)
            ans = ans->next;

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Node* num1 = buildList(n);
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

/* Sample Input
2
2 3
4 5
3 4 5
4 2
0 0 6 3
0 7

Sample Output
3 9 0 
7 0 

*/