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

void solve(int t) {
    int k;
    cin >> k;
    vector<int> ns;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        ns.pb(n);
        int useless;
        for (int i = 2; i <= n; i++)
            cin >> useless;

    }

    sort(ns.begin(), ns.end(), greater<int>());    
    
    int ans = 0;
    for (int n : ns) {
        for (int i = 24; i >= 0; i--) {
            int n_i = n & (1 << i);
            if (n_i == 0)
                continue;

            int ans_i = ans & (1 << i);
            if (ans_i == 0)
                ans |= n;
            else {
                ans |= (1 << i) - 1;
                break;
            }
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
        solve(t);
    }

    return 0;
}