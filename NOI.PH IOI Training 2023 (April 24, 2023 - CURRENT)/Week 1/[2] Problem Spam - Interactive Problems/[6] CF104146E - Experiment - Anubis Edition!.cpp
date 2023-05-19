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

int n = 15, M = 14348906;
vector<int> wgts = {0, 2, 6, 18, 54, 162, 486, 1458, 4374, 13122, 39366, 118098, 354294, 1062882, 3188646, 9565938, 28697814};

void query(int x) {
    vector<int> l_idxs = {0}, r_idxs;
    for (int i = 1; i <= n; i++) {
        if (x % wgts[i + 1] == wgts[i]) {
            r_idxs.push_back(i);
            x -= wgts[i];
        } else if (x % wgts[i + 1] == 2 * wgts[i]) {
            l_idxs.push_back(i);
            x += wgts[i];
        }
    }

    cout << "WEIGH" << endl;
    cout << l_idxs.size() << endl;
    for (int &l : l_idxs) {
        cout << l << ' ';
    }
    cout << endl;
    cout << r_idxs.size() << endl;
    for (int &r : r_idxs) {
        cout << r << ' ';
    }
    cout << endl;

    return;
}

void solve() {
    query(M);
    string res;
    cin >> res;

    if (res == ">") {
        cout << "VERDICT" << endl;
        cout << "HEAVY" << endl;
        return;
    }

    int ans = 0;
    for (int i = 8388608; i >= 2; i >>= 1) {
        if (ans + i > M) {
            continue;
        }
        
        query(ans + i);
        cin >> res;

        if (res == "<") {
            continue;
        }

        ans += i;

        if (res == "=") {
            cout << "VERDICT" << endl;
            cout << "EXACT" << endl;
            cout << ans << endl;
            return;
        }
    }

    ans++;
    cout << "VERDICT" << endl;
    cout << "EXACT" << endl;
    cout << ans << endl;

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

    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << wgts[i] << ' ';
    }
    cout << endl;
    cout << M << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();

        string res;
        cin >> res;

        if (res == ">:(") {
            return 0;
        }
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}