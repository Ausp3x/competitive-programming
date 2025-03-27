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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    lng K;
    cin >> n >> K;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    map<int, int> cnt;
    for (int a : A)
        cnt[a]++;

    lng ans = 0, k_prv = 0, v_prv = 0;
    for (auto &[k, v] : cnt) {
        ans += v_prv;
        n -= v_prv;

        lng add = min(1ll * (k - k_prv) * n, K);
        ans += add;
        K -= add;

        if (K == 0)
            break;

        k_prv = k;
        v_prv = v;
    }

    cout << ans << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}