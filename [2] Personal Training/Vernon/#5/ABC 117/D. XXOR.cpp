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

void solve() {
    int n;
    lng k;
    cin >> n >> k;
    lng a_sum = 0;
    vector<lng> A(n);
    for (lng &a : A) {
        cin >> a;
        a_sum += a;
    }

    if (k == 0) {
        cout << a_sum << endl;
        return;
    }

    int N = 42;
    vector<lng> cnts(N);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < N; j++)
            if (A[i] & (1ll << j))
                cnts[j]++;

    vector<lng> k_pow2(N + 1);
    for (int i = 1; i <= N; i++) {
        k_pow2[i] += k_pow2[i - 1];
        k_pow2[i] += (2 * cnts[i - 1] < n ? 1ll << (i - 1) : 0); 
    }

    function<lng(lng)> f = [&](lng k) {
        lng res = 0;
        for (int i = 0; i < N; i++)
            if (!(k & (1ll << i)))
                res += cnts[i] << i;
            else
                res += (n - cnts[i]) << i;

        return res;
    };

    lng k_cur = 0, ans = f(k);
    while (k_cur < k) {
        for (int i = N; i >= 0; i--)
            if (k_cur + k_pow2[i] <= k) {
                ans = max(ans, f(k_cur + k_pow2[i]));
                break;
            }

        for (int i = N; i >= 0; i--)
            if (k_cur + (1ll << i) <= k) {
                k_cur += (1ll << i);
                break;
            }
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