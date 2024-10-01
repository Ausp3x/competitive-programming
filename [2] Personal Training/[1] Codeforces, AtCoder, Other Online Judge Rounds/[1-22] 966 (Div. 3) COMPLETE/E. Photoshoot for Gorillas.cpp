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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<lng> A(w);
    for (lng &a : A)
        cin >> a;

    vector<lng> r_cnts(k + 1);
    for (int i = 0; i < n; i++) 
        r_cnts[min(i + k - 1, n - 1) - max(i - k + 1, 0) + 1 - k + 1]++;
    while (r_cnts.back() == 0)
        r_cnts.pop_back();

    vector<lng> c_cnts(k + 1);
    for (int i = 0; i < m; i++)
        c_cnts[min(i + k - 1, m - 1) - max(i - k + 1, 0) + 1 - k + 1]++;
    while (c_cnts.back() == 0)
        c_cnts.pop_back();

    map<lng, lng> M;
    for (lng i = r_cnts.size() - 1; i >= 1; i--)
        for (lng j = c_cnts.size() - 1; j >= 1; j--)
            M[i * j] += r_cnts[i] * c_cnts[j];

    // for (int x : r_cnts)
    //     cout << x << ' ';
    // cout << endl;
    // for (int x : c_cnts)
    //     cout << x << ' ';
    // cout << endl;

    int idx = 0;
    lng ans = 0;
    sort(A.begin(), A.end(), greater<lng>());
    for (auto [k, v] : M | views::reverse) {
        while (v--) {
            if (idx == A.size()) {
                cout << ans << endl;
                return;
            }

            ans += k * A[idx];
            idx++;
        }
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