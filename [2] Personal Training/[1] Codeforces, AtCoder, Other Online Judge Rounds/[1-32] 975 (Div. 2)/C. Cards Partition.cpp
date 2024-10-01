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
    lng n, k;
    cin >> n >> k;
    lng A_sum = 0;
    vector<lng> A(n);
    for (lng &a : A) {
        cin >> a;
        A_sum += a;
    }

    sort(A.begin(), A.end());

    lng ans = 1;
    for (lng i = 2; i <= n; i++) {
        lng cur = (A_sum + k) / i * i;
        if (cur < A_sum)
            continue;

        if (A.back() > cur / i)
            continue;

        ans = i;
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