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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    lng n, m, k;
    cin >> n >> m >> k;
    vector<lng> H(n);
    for (lng &h : H)
        cin >> h;
    vector<lng> X(n);
    for (lng &x : X)
        cin >> x;

    lng lo = 0, hi = 10'000'000'000;
    while (hi - lo > 1) {
        lng md = (lo + hi) / 2;

        map<lng, int> M;
        for (int i = 0; i < n; i++) {
            if (md * m - H[i] < 0) 
                continue;

            lng d = (md * m - H[i]) / md;            
            M[X[i] - d]++;
            M[X[i] + d + 1]--;
        }

        vector<pair<lng, int>> V;
        for (auto &[a, b] : M)
            V.pb({a, b});

        sort(V.begin(), V.end());
    
        bool chk = false;
        int cnt = 0;
        for (auto &[a, b] : V) {
            cnt += b;
            chk |= cnt >= k;
        }
        
        if (chk)
            hi = md;
        else
            lo = md;
    }

    if (hi == 10'000'000'000)
        cout << -1 << endl;
    else
        cout << hi << endl;

    // cout << endl << endl;
    
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