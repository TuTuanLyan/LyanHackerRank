#include <vector>
#include <iostream>
using namespace std;
int sw = 0;
int ins = 0;

int partition(vector<int>& a, int p, int r) {
    int pivot, t;
    pivot = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            sw++;
        }
    }
    i++;
    t = a[i];
    a[i] = a[r];
    a[r] = t;
    sw++;
    return i;
}

void quicksort(vector<int>& a, int p, int r) {
    int q;
    if (p < r) {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

void insertionsort(vector<int>& a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        int value = a[i];
        while (j > 0 && a[j - 1] > value) {
            a[j] = a[j - 1];
            j--;
            ins++;
        }
        a[j] = value;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r[i] = a[i];
    }
    insertionsort(r, n);
    quicksort(a, 0, n - 1);
    cout << ins - sw;
}
