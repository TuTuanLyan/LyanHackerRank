#include <bits/stdc++.h>

using namespace std;


int main() {
    int Q; cin >> Q;
    stack<string> state;
    string s = "";
    while(Q--) {
        int x; cin >> x;
        if(x == 1) {
            state.push(s);
            string w; cin >> w;
            s += w;
        }else if(x == 2) {
            int k; cin >> k;
            state.push(s);
            s = s.substr(0, (size_t)(s.size() - k));
        }else if(x == 3) {
            int k; cin >> k;
            cout << s[k-1] << '\n';
        }else if(x == 4) {
            s = state.top();
            state.pop();
        }
    }
    return 0;
}
