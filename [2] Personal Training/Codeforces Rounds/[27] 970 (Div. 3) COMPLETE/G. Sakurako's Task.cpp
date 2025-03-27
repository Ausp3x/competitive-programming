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
    lng k;
    cin >> n >> k;
    lng A_gcd = 0, A_max = 0;
    vector<lng> A(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A_gcd = gcd(A_gcd, A[i]);
        A_max = max(A_max, A[i]);
    }
    A[n] = INF64;

    if (n == 1) {
        cout << k - 1 + (A_max <= k - 1) << endl;
        return;
    }

    sort(A.begin(), A.end());

    lng a_new = 0;
    for (int i = 0; i < n; i++) {
        A[i] = a_new;
        a_new += A_gcd;
    }

    lng ans = -1;
    for (int i = 0; i <= n; i++) {
        if (k <= A[i] - ans - 1)
            break;

        k -= max(A[i] - ans - 1, 0ll);
        ans = A[i];
    }
    ans += k;

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