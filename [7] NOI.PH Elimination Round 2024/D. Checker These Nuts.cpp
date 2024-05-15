// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<lng> as(n);
    for (lng &a : as) {
        cin >> a;
    }
    vector<int> ps(n);
    for (int &p : ps) {
        cin >> p;
        p--;
    }

    if (n == 1) {
        cout << as[0] << endl;
        return;
    }

    if (n == 2) {
        if (k == 1) {
            cout << as[0] + as[1] << endl;
            return;
        }

        cout << max(as[0], as[1]) << endl;
        return;
    }

    if (n == 3) {
        if (k == 1) {
            cout << as[0] + as[1] + as[2] << endl;
            return;
        }

        if (k == 3) {
            cout << max({as[0], as[1], as[2]}) << endl;
            return;
        }
        
        vector<lng> sorted_as(3);
        for (int i = 0; i < n; i++) {
            sorted_as[i] = as[ps[i]];
        }

        cout << max(sorted_as[0] + sorted_as[2], sorted_as[1]) << endl;
        return;
    }

    vector<lng> sorted_as(n);
    for (int i = 0; i < n; i++) {
        sorted_as[i] = as[ps[i]];
    }

    lng ans = 0, neg = 0;
    vector<int> remove_neg(n + k);
    for (int i = 0; i < n; i++) {
        neg += remove_neg[i]; 
        
        if (sorted_as[i] + neg < 0) {
            continue;
        }

        ans += sorted_as[i] + neg;    
        remove_neg[i + k] = sorted_as[i] + neg;
        neg = -sorted_as[i];
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