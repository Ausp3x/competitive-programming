// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

#define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int n;
    cin >> n;

    int prv;
    cout << "? 1 " << n << endl;
    cin >> prv;

    int cur;
    vector<int> ans(n + 1);
    for (int i = n - 1; i > 1; i--) {
        cout << "? 1 " << i << endl;
        cin >> cur;
        ans[i + 1] = prv - cur;
        if (i > 2) {
            prv = cur;
        }
    }
    
    int two_to_three;
    cout << "? 2 3" << endl;
    cin >> two_to_three;
    ans[1] = prv - two_to_three;
    ans[2] = cur + two_to_three - prv;

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' '; 
    }
    cout << endl;

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