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
    int n, m;
    lng d;
    cin >> n >> m >> d;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    lng ans = 0, sum = 0;
    multiset<int> M;
    for (int i = 0; i < n; i++) {
        ans = max(ans, A[i] + sum - (i + 1) * d);
        
        if (m == 1)
            continue;

        if (A[i] <= 0)
            continue;

        if (M.size() < m - 1) {
            sum += A[i];
            M.insert(A[i]);
            continue;
        }

        if (A[i] <= *M.begin())
            continue;

        sum -= *M.begin();
        M.erase(M.begin());
        sum += A[i];
        M.insert(A[i]);
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