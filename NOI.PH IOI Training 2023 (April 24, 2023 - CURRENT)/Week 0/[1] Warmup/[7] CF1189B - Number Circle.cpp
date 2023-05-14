// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define DEBUG

void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }

    sort(as.begin(), as.end(), greater<int>());
    
    if (as[0] >= as[1] + as[2]) {
        cout << "NO\n";
        return;
    }

    swap(as[0], as[1]);
    cout << "YES\n";
    for (int &a : as) {
        cout << a << ' '; 
    }
    cout << '\n';

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}