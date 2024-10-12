#include <bits/stdc++.h>
using namespace std;



void quickSort(vector <int> &arr) {
	// Complete this function
    if(arr.size() <= 1) return;
    vector<int> l,r;
        
    int p = arr[0];
    
    for(auto i = 1; i < arr.size(); i++) {
        if(arr[i] < p) l.push_back(arr[i]);
        else r.push_back(arr[i]);
    }
    
    quickSort(l);
    quickSort(r);
    
    arr = {};
    for(auto x : l) arr.push_back(x);
    arr.push_back(p);
    for(auto x : r) arr.push_back(x);
    
    for(auto x : arr) cout << x << ' ';
    cout << '\n';
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}