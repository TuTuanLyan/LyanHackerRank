#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;
    stack<int> deq, enq;
    
    while (n--) {
        int t; cin >> t;
        if (t == 1) {
            int x; 
            cin >> x;
            enq.push(x);
        } 
        else if (t == 2) {
            if (deq.empty()) {
                while (!enq.empty()) {
                    deq.push(enq.top());
                    enq.pop();
                }
            }
            if (!deq.empty()) deq.pop();
        } 
        else if (t == 3) {
            if (deq.empty()) {
                while (!enq.empty()) {
                    deq.push(enq.top());
                    enq.pop();
                }
            }
            if (!deq.empty()) cout << deq.top() << '\n';
        }
    }
    
    return 0;
}
