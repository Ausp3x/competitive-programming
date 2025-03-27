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

void solve() {
    int n;
    cin >> n;
    int a_max = -1;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        a_max = max(a_max, A[i]);
    }
    
    int largest_idx = -1;
    for (int i = 1; i <= n; i++)
        if (A[i] == a_max) {
            largest_idx = i;
            break;
        }

    a_max = -1;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        a_max = max(a_max, A[i]);
        ans[i] = a_max;
    }

    // for (int i = 1; i <= n; i++)
    //     cout << ans[i] << ' ';
    // cout << endl;

    deque<pair<int, int>> dq;
    int a_min = a_max;
    for (int i = largest_idx; i <= n; i++)
        a_min = min(a_min, A[i]);
    dq.pb({a_min, a_max});
    for (int i = largest_idx - 1; i >= 1;) {
        int j = i;

        while (!dq.empty() && ans[i] <= dq.front().fi)
            dq.pop_front();

        a_min = A[i];
        while (j - 1 >= 1 && ans[j - 1] == ans[i]) {
            j--;
            a_min = min(a_min, A[j]);
        }

        // cout << j << ' ' << i << endl;

        if (!dq.empty()) {
            for (int k = j; k <= i; k++)
                ans[k] = dq.front().se;
            dq.front().fi = min(dq.front().fi, a_min);
        } else {
            dq.pb({a_min, ans[i]});
        }

        i = j - 1;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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