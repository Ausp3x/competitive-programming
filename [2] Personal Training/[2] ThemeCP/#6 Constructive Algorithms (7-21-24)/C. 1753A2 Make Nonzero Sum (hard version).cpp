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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    int A_sum = accumulate(A.begin(), A.end(), 0);

    if (A_sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> grps(n);
    iota(grps.begin(), grps.end(), 0);
    for (int i = 1; i < n; i++) {
        if (abs(A_sum - 2 * A[i]) < abs(A_sum)) {
            A_sum -= 2 * A[i];
            grps[i] = grps[i - 1];
            i++;
        }
    }

    vector<pair<int, int>> ans = {{1, 1}};
    for (int i = 1; i < n; i++) {
        if (grps[i] == grps[i - 1])
            ans.back().se = i + 1;
        else
            ans.pb({i + 1, i + 1});
    }
    
    cout << (A_sum == 0 ? ans.size() : -1) << endl;
    for (auto [x, y] : ans)
        cout << x << ' ' << y << endl;

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