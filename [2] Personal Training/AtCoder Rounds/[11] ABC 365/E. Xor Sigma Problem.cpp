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
    int N;
    cin >> N;
    lng ans = 0;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
        ans -= a;
    }
    
    lng mul = 1;
    for (int i = 0; i < 31; i++) {        
        bool chk = false;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] & mul)
                chk ^= 1;
            
            if (chk)
                cnt++;
        }

        for (int j = 0; j < N; j++) {
            ans += mul * cnt;

            if (A[j] & mul)
                cnt = N - cnt - j;
        }

        mul *= 2;
    }
    
    cout << ans << endl;

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