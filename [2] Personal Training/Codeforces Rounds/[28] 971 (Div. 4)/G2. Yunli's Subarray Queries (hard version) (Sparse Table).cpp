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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    int len = n - k + 1;
    map<int, int> cnts;
    set<pair<int, int>> S;
    vector<int> C(len + 1);
    for (int i = 1; i <= k; i++)
        cnts[A[i] - i]++;
    for (auto &[a, b] : cnts)
        S.insert({b, a});
    C[1] = k - S.rbegin()->first; 
    for (int i = k + 1; i <= n; i++) {
        int l = A[i - k] - i + k, r = A[i] - i;

        if (S.find({cnts[l], l}) != S.end())
            S.erase({cnts[l], l});
        if (S.find({cnts[r], r}) != S.end())
            S.erase({cnts[r], r});

        cnts[l]--;
        cnts[r]++;        

        S.insert({cnts[l], l});
        S.insert({cnts[r], r});

        C[i - k + 1] = k - S.rbegin()->first;
    }

    // for (int x : C)
    //     cout << x << ' ';
    // cout << endl;
    
    vector<int> idxs(len + 1, len + 1);
    // idx, val
    stack<pair<int, int>> stk;
    for (int i = 1; i <= len; i++) {
        while (!stk.empty()) {
            if (stk.top().se <= C[i])
                break;
            
            idxs[stk.top().fi] = i;
            stk.pop();
        }

        stk.push({i, C[i]});
    }

    // for (int x : idxs) 
    //     cout << x << ' ';
    // cout << endl;

    // sum, next idx
    vector<vector<pair<lng, int>>> sptb(20, vector<pair<lng, int>>(len + 1, {-1, -1}));
    for (int j = 1; j <= len; j++)
        sptb[0][j] = {1ll * C[j] * (idxs[j] - j), idxs[j]};
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= len; j++) {
            if (sptb[i - 1][j].se == -1 || sptb[i - 1][j].se == len + 1)
                continue;
            
            sptb[i][j] = {sptb[i - 1][j].fi + sptb[i - 1][sptb[i - 1][j].se].fi, sptb[i - 1][sptb[i - 1][j].se].se};
        }
    }

    // for (int i = 0; i < 20; i++) {
    //     for (int j = 1; j <= len; j++) 
    //         cout << '[' << sptb[i][j].fi << ", " << sptb[i][j].se << "] ";
    //     cout << endl;
    // }

    while (q--) {
        int l, r;
        cin >> l >> r;
        r -= k - 1;

        lng ans = 0;
        for (int i = 19; i >= 0; i--) {
            if (l > r)
                break;

            if (sptb[i][l].se == -1)
                continue;
            
            if (sptb[i][l].se > r + 1)
                continue;

            ans += sptb[i][l].fi;
            l = sptb[i][l].se; 
        }
        if (l <= r) 
            ans += 1ll * C[l] * (r - l + 1);
    
        cout << ans << endl;
    }
    
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