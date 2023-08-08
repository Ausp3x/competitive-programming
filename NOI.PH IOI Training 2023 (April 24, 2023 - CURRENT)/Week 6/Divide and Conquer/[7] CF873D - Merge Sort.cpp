// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

int k;

void mergeUnsort(int l, int r, vector<int> &arr) {
    int d = r - l;
    if (k == 0 || d == 1) { 
        return;
    }

    d /= 2;
    int md = (l + r) / 2;
    swap(arr[md - 1], arr[md]);
    
    k -= 2;
    mergeUnsort(l, md, arr);
    mergeUnsort(md, r, arr);

    return;
}

void solve() {
    int n;
    cin >> n >> k;
    
    if (k % 2 == 0) {
        cout << -1 << endl;
        
        return;
    }

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    k--;
    mergeUnsort(0, n, arr);
    
    if (k > 0) {
        cout << -1 << endl;
        
        return;
    }

    for (int &a : arr) {
        cout << a << ' ';
    }
    cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}