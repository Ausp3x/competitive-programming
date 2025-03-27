// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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

int const MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> lg2(n + 1);
    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;
    vector<int> A(n + 1);
    vector<vector<lng>> sptb(20, vector<lng>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sptb[0][i] = i;
    }

    for (int l = 1; l < 20; l++) 
        for (int i = 1; i + (1 << (l - 1)) <= n; i++) {
            lng x = sptb[l - 1][i];
            lng y = sptb[l - 1][i + (1 << (l - 1))];
            sptb[l][i] = (A[x] < A[y] ? x : y);  
        }
    
    function<lng(int, int, int)> dfs = [&](int l, int r, int msk) {
        if (l > r)
            return 1ll;
        
        int k = lg2[r - l + 1];
        lng x = sptb[k][l];
        lng y = sptb[k][r - (1 << k) + 1];
        lng idx = (A[x] < A[y] ? x : y);

        lng L = dfs(l, idx - 1, msk | 1);
        lng R = dfs(idx + 1, r, msk | 2);
        lng res = (L * R) % MOD;

        if (msk & 1)
            (res += L) %= MOD;
        if (msk & 2)
            (res += R) %= MOD;
        if (msk == 3)
            (res += MOD - 1) %= MOD;

        return res;
    };

    cout << dfs(1, n, 0) << endl;    
    
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