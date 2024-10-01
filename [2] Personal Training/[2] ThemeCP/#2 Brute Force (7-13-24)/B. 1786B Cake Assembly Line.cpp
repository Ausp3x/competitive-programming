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
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    vector<int> B(n);
    for (int &b : B)
        cin >> b;
    
    int l = -INF32, r = INF32;
    for (int i = 0; i < n; i++) {
        int cur_l = (A[i] - w) - (B[i] - h);
        int cur_r = (A[i] + w) - (B[i] + h);
        
        l = max(l, cur_l);
        r = min(r, cur_r);
    }

    cout << (l <= r ? "YES" : "NO") << endl;

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