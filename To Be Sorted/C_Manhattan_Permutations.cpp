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
    lng k;
    cin >> n >> k;

    if (k % 2 != 0) {
        cout << "No" << endl;
        return;    
    }

    k /= 2;
    vector<int> ans(n + 1);
    for (int i = 1; i <= (n + 1) / 2; i++) {
        int d = n - 2 * i + 1;
        if (k >= d) {
            ans[i] = n - i + 1;
            ans[n - i + 1] = i;
            k -= d;
            continue;
        }
        
        d = min<lng>(d, k);

        ans[i + d] = i; 
        for (int j = i + 1; j <= n - i + 1; j++) {
            if (j - i <= d)
                ans[j - 1] = j;
            else
                ans[j] = j;
        }
        k -= d;

        break;
    }

    // cout << k << ' ';
    if (k > 0) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
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