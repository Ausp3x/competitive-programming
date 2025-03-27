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
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> P[i];

    if (n == 1) {
        cout << P[1] << endl;
        return;
    }

    int p_max = 0, p_max_idx = n + 1;
    vector<int> Q(n + 1);
    Q[n] = n + 1;
    for (int i = n - 1; i >= 1; i--) {
        if (P[i + 1] > p_max) {
            p_max = P[i + 1];
            p_max_idx = i + 1;
        }
        Q[i] = p_max_idx;
    }

    vector<int> bst(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> cur(1);
        for (int j = Q[i]; j <= n; j++)
            cur.pb(P[j]);
        for (int j = Q[i] - 1; j >= i; j--)
            cur.pb(P[j]);
        for (int j = 1; j < i; j++)
            cur.pb(P[j]);

        if (cur > bst)
            bst = cur;
    }

    for (int i = 1; i <= n; i++)
        cout << bst[i] << ' ';
    cout << endl;

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