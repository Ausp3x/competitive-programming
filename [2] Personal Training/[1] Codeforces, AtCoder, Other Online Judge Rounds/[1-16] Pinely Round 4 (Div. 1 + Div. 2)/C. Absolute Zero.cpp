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
    bool has_evn = false, has_odd = false;
    int A_max = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        has_evn |= a % 2 == 0;
        has_odd |= a % 2 == 1;
        A_max = max(A_max, a);
    }
    
    if (has_evn && has_odd) {
        cout << -1 << endl;
        return;
    }

    if (A_max == 0) {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    int A_log2 = log2(A_max);
    vector<int> ans;
    for (int i = A_log2; i >= 0; i--) {
        ans.pb(1 << i);
    }
    if (has_evn)
        ans.pb(1);

    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << ' ';
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