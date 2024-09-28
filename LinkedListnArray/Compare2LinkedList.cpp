#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
};

int compare(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val != head2->val) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if (head1 == nullptr && head2 == nullptr) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n1, n2;
        cin >> n1;
        
        Node* head1 = nullptr;
        Node* cur = nullptr;
        
        for (int i = 0; i < n1; i++) {
            int value;
            cin >> value;
            Node* newNode = new Node{value, nullptr};
            if (head1 == nullptr) {
                head1 = newNode;
                cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
        }
        
        cin >> n2;
        
        Node* head2 = nullptr;
        cur = nullptr;
        
        for (int i = 0; i < n2; i++) {
            int value;
            cin >> value;
            Node* newNode = new Node{value, nullptr};
            if (head2 == nullptr) {
                head2 = newNode;
                cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
        }
        
        cout << compare(head1, head2) << endl;
    }
    
    return 0;
}

