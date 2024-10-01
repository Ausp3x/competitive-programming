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
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end(), greater<int>());

    lng ans = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        int d = min(A[i] - A[i + 1], k);
        k -= d;
        A[i + 1] += d;
        ans += A[i] - A[i + 1];
    }
    if (n % 2 == 1)
        ans += A[n - 1];

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