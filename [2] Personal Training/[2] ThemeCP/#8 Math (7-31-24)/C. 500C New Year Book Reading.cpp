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
    int n, m;
    cin >> n >> m;
    vector<int> W(n);
    for (int &w : W)
        cin >> w;
    vector<int> B(m);
    for (int &b : B) {
        cin >> b;
        b--;
    }

    int ans = 0;
    deque<int> dq;
    for (int i = 0; i < m; i++) {
        int idx = -1, w_sum = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == B[i]) {
                idx = j;
                break;
            }

            w_sum += W[dq[j]];
        }

        ans += w_sum;
        if (idx != -1) {
            vector<int> lifted;
            while (dq.front() != B[i]) {
                lifted.pb(dq.front());
                dq.pop_front();
            }
            dq.pop_front();

            for (int i = lifted.size() - 1; i >= 0; i--)
                dq.push_front(lifted[i]);
        }
        dq.push_front(B[i]);

        // for (int x : dq)
        //     cout << x << ' ';
        // cout << endl;
    }

    cout << ans << endl;
    
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