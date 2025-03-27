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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    vector<vector<int>> segments = {{A[0]}};
    for (int i = 1; i < n; i++) {
        if (A[i] > segments.back().back() + 1)
            segments.pb({A[i]});
        else
            segments.back().pb(A[i]);
    }

    int ans = 0;
    for (auto seg : segments) {
        int j = 0;
        for (int i = 0; i < seg.size(); i++) {
            while (j + 1 < seg.size() && seg[j + 1] < seg[i] + k)
                j++;

            ans = max(ans, j - i + 1);
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