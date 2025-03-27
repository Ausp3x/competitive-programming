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

lng const MOD = 1'000'000'000'000'000'009;

bool isPermutation(array<int, 26> &x, array<int, 26> &y) {
    for (int i = 0; i < 26; i++) 
        if (x[i] != y[i])
            return false;

    return true;
}

void solve() {
    string N;
    cin >> N;
    string H;
    cin >> H;

    int n = N.size(), h = H.size();
    if (n > h) {
        cout << 0 << endl;
        return;
    }

    lng p = 31;
    lll p_pow = 1, hash = 0;
    array<int, 26> N_cnts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                   Hs_cnts = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = n - 1; i >= 0; i--) {
        N_cnts[N[i] - 'a']++;
        Hs_cnts[H[i] - 'a']++;
        
        hash += (H[i] - 'a' + 1) * p_pow;
        hash %= MOD;
        if (i > 0)
            p_pow = (p_pow * p) % MOD;
    }

    int ans = 0;
    map<lng, int> chks;
    chks[lng(hash)]++;
    if (isPermutation(N_cnts, Hs_cnts) && chks[lng(hash)] == 1)
        ans++;
    for (int i = n; i < h; i++) {
        Hs_cnts[H[i - n] - 'a']--;
        Hs_cnts[H[i] - 'a']++;

        hash -= (H[i - n] - 'a' + 1) * p_pow;
        ((hash %= MOD) += MOD) %= MOD;
        hash *= p;
        hash %= MOD;
        hash += (H[i] - 'a' + 1);
        hash %= MOD;

        chks[lng(hash)]++;
        if (isPermutation(N_cnts, Hs_cnts) && chks[lng(hash)] == 1)
            ans++;
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