/*

In this challenge, we should change the default template from int to long long and use stdin
If you use int to solve this problem you will have 6 wrong test cases because int overflow.

Quote someone: :D
    what the hell , if you are getting wrong answer and if you think your code is correct , 
    then the convert the integer to long in pre written code , 
    they said that the range is in integer's range but it isn't.

*/

#include <bits/stdc++.h>

using namespace std;

void merge(vector<long long> &a, int l, int m, int r, long long &cnt) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    vector<long long> L(n1);
    vector<long long> R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i + 1];
    
    int i = 0, j = 0, k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            cnt += (n1 - i);
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void furinaHelp(vector<long long> &a, int l, int r, long long &cnt) {
    if (l >= r) return;
    int m = (l + r) / 2;
    furinaHelp(a, l, m, cnt);
    furinaHelp(a, m + 1, r, cnt);
    merge(a, l, m, r, cnt);
}

long long insertionSort(vector<long long> arr) {
    long long cnt = 0;
    furinaHelp(arr, 0, arr.size() - 1, cnt);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long result = insertionSort(arr);
        cout << result << "\n";
    }

    return 0;
}
