#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(vector<int> &a, int l, int r) {
    if(r - l <= 1) return;
    
    int p = a[r - 1];
    int f = l;
    
    for(int i = l; i < r - 1; i++) {
        if(a[i] < p) {
            swap(a[i], a[f]);
            f++;
        } 
    }
    
    swap(a[f], a[r - 1]);
    
    for(auto x : a) cout << x << ' ';
    cout << '\n';
    
    quickSort(a, l, f);
    quickSort(a, f + 1, r);   
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    quickSort(a, 0, a.size());
    return 0;
}
