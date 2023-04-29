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
    string s;
    cin >> s;

    int n = s.size();
    map<string, bool> str_chks = {{"dream", true}, {"dreamer", true}, {"erase", true}, {"eraser", true}};
    for (int i = n - 1; i >= 0; ) {
        if (s.substr(i - 4, 5) == "dream" || s.substr(i - 4, 5) == "erase") {
            i -= 5;
            continue;
        }
        if (s.substr(i - 5, 6) == "eraser") {
            i -= 6;
            continue;
        }
        if (s.substr(i - 6, 7) == "dreamer") {
            i -= 7;
            continue;
        }
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

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