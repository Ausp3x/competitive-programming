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
    vector<int> V(178);


    for (int i = 0; i < 4; i++) {
        int s, e;
        cin >> s >> e;
        
        V[s] |= 1 << i;
        V[e] |= 1 << i;
    }

    int ans = 0;
    for (int i = 0; i < 178; i++) {
        if (i > 0)
            V[i] = V[i] ^ V[i - 1];

        ans += V[i] == 4;
    }

    if (ans == 0) {
        cout << "No guitar solo :(" << endl;
        return;
    }

    cout << "Guitar solo (" << ans << " sec.)" << endl;

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