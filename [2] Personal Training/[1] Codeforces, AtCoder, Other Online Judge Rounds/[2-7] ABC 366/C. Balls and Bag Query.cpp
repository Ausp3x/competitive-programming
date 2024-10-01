// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int Q;
    cin >> Q;

    map<int, int> cnts;
    while (Q--) {
        int i;
        cin >> i;
        
        if (i == 1) {
            int x;
            cin >> x;

            cnts[x]++;
        } else if (i == 2) {
            int x;
            cin >> x;

            cnts[x]--;
            if (cnts[x] == 0)
                cnts.erase(x);
        } else if (i == 3) {
            cout << cnts.size() << endl;
        } else {
            return;
        }
    }

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