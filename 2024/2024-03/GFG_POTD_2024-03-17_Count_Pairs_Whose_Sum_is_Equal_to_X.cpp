// GFG POTD 2024/03/17
// Count Pairs Whose Sum is Equal to X
// Easy

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

void append(Node** headRef, Node** tailRef, int newData) {
    Node* new_node = new Node(newData);

    if (*headRef == NULL)
        *headRef = new_node;
    else
        (*tailRef)->next = new_node;

    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}

class Solution {
public:
    int countPairs(Node* head1, Node* head2, int x) {
        set<int> s1;

        Node* tmp = head1;
        while (tmp) {
            s1.insert(tmp->data);
            tmp = tmp->next;
        }

        tmp = head2;
        int ans = 0;
        while (tmp) {
            if(s1.find(x - tmp->data) != s1.end())
                ans++;
            tmp = tmp->next;
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node* head1 = NULL;
        Node* tail1 = NULL;
        Node* tail2 = NULL;
        Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1 >> n2 >> x;

        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }

        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}

/* Sample Input
2

6 3 15
1 2 3 4 5 6
11 12 13

4 4 10
7 5 1 3
3 5 2 8

Sample Output
3
2 

*/