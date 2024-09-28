#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* merge(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* head = nullptr;
    
    if (head1->val < head2->val) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }

    Node* cur = head;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val < head2->val) {
            cur->next = head1;
            head1 = head1->next;
        } else {
            cur->next = head2;
            head2 = head2->next;
        }
        cur = cur->next;
    }

    if (head1 != nullptr) cur->next = head1;
    if (head2 != nullptr) cur->next = head2;
    
    return head;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n1, n2;
        cin >> n1;
        
        Node* head1 = nullptr;
        Node* cur1 = nullptr;
        
        for (int i = 0; i < n1; i++) {
            int value;
            cin >> value;
            Node* newNode = new Node{value, nullptr};
            if (head1 == nullptr) {
                head1 = newNode;
                cur1 = newNode;
            } else {
                cur1->next = newNode;
                cur1 = newNode;
            }
        }
        
        cin >> n2;
        
        Node* head2 = nullptr;
        Node* cur2 = nullptr;

        for (int i = 0; i < n2; i++) {
            int value;
            cin >> value;
            Node* newNode = new Node{value, nullptr};
            if (head2 == nullptr) {
                head2 = newNode;
                cur2 = newNode;
            } else {
                cur2->next = newNode;
                cur2 = newNode;
            }
        }
        
        Node* res = merge(head1, head2);
        while (res != nullptr) {
            cout << res->val << ' ';
            res = res->next;
        }
        cout << endl;
    }
    
    return 0;
}
