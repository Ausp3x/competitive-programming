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

/*
1 2 3
2 3 1 <- 
3 1 2 <-

1 2 3 1 2 3

1 2 3 4 5 6 7 8 9
1 1 1 2 2 2 3 3 3
*/

void solve() {
    lng n;
    int q;
    cin >> n >> q;
    lng A_sum = 0;
    vector<lng> A(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        A_sum += A[i];
        A[n + i] = A[i];
    }

    for (int i = 1; i <= 2 * n; i++)
        A[i] += A[i - 1];

    while (q--) {
        lng l, r;
        cin >> l >> r;
    
        lng l_n = (l + n - 1) / n;
        lng r_n = (r + n - 1) / n;
        lng L = (l_n - 1) * n + 1;
        lng R = r_n * n;

        lng ans = (r_n - l_n + 1) * A_sum;
        // cout << ans << ' ';
        ans -= A[((l - 1) % n + 1) + (l_n - 1) - 1] - A[((L - 1) % n + 1) + (l_n - 1) - 1];
        ans -= A[((R - 1) % n + 1) + (r_n - 1)] - A[((r - 1) % n + 1) + (r_n - 1)];

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