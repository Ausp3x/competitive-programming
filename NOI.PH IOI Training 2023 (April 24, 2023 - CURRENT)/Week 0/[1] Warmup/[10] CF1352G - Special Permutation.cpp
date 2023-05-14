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
    
    if (n <= 3) {
        cout << -1 << '\n';
        return;
    }

    deque<int> dq;
    dq.push_back(3);
    dq.push_back(1);
    dq.push_back(4);
    dq.push_back(2);
    for (int i = 5; i <= n; i++) {
        if (i % 2 == 0) {
            dq.push_back(i);
        } else {
            dq.push_front(i);
        }
    }

    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
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
    cin >> t;
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