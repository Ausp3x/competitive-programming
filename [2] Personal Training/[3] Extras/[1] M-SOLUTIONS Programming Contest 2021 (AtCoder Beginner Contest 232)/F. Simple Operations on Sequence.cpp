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

int n, x;
lng y;
vector<int> as, bs;

vector<vector<lng>> memo;
lng dp(int b_idx, int used_as) {
    if (b_idx == n) {
        return 0;
    }
    
    if (memo[b_idx][used_as] != INF64) {
        return memo[b_idx][used_as];
    } 

    for (int i = 0; i < n; i++) {
        if (used_as & (1 << i)) {
            continue;
        }

        int x_cnt = abs(bs[b_idx] - as[i]);

        int y_cnt = 0;
        for (int j = 0; j < i; j++) {
            y_cnt += !(used_as & (1 << j));
        }

        memo[b_idx][used_as] = min(memo[b_idx][used_as], 
                                   1ll * x_cnt * x + y_cnt * y + dp(b_idx + 1, used_as | (1 << i)));
    }

    return memo[b_idx][used_as];
}

void solve() {
    cin >> n >> x >> y;
    as.resize(n);
    for (int &a : as) {
        cin >> a;
    }
    bs.resize(n);
    for (int &b : bs) {
        cin >> b;
    }

    memo.resize(n, vector<lng>(1 << n, INF64));
    
    cout << dp(0, 0) << endl;

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