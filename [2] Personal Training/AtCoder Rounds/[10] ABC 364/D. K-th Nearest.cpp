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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int &a : A)
        cin >> a;
    
    sort(A.begin(), A.end());

    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        int l = -1, r = 1000000000;
        while (r - l > 1) {
            int m = (l + r) / 2;

            int ll1 = -1, rr1 = N;
            while (rr1 - ll1 > 1) {
                int mm = (ll1 + rr1) / 2;

                if (A[mm] >= b - m)
                    rr1 = mm;
                else 
                    ll1 = mm;
            }

            int ll2 = -1, rr2 = N;
            while (rr2 - ll2 > 1) {
                int mm = (ll2 + rr2) / 2;

                if (A[mm] <= b + m)
                    ll2 = mm;
                else
                    rr2 = mm;
            }

            if (ll2 - rr1 + 1 >= k)
                r = m;
            else
                l = m;

            // cout << l << ' ' << r << endl;
            // cout << b - m << ' ' << ll1 << ' ' << rr1 << ' ' << b + m << ' ' << ll2 << ' ' << rr2 << endl;
        }

        cout << r << endl;
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}