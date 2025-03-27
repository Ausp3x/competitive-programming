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

int N = 4000000;

void solve() {
    int n, D;
    cin >> n >> D;
    vector<int> X(N + 1), Y(N + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        X[x + N / 2]++;
        Y[y + N / 2]++;
    }

    int X_cnt = 0, Y_cnt = 0;
    lng X_cur = 0, Y_cur = 0;
    vector<lng> X_sum(N + 1), Y_sum(N + 1);
    for (int i = 0; i <= N; i++) {
        X_cur += X_cnt;
        Y_cur += Y_cnt;
        X_sum[i] += X_cur;
        Y_sum[i] += Y_cur;
    
        X_cnt += X[i];
        Y_cnt += Y[i];
    }

    X_cnt = 0; Y_cnt = 0;
    X_cur = 0; Y_cur = 0;
    for (int i = N; i >= 0; i--) {
        X_cur += X_cnt;
        Y_cur += Y_cnt;
        X_sum[i] += X_cur;
        Y_sum[i] += Y_cur;
    
        X_cnt += X[i];
        Y_cnt += Y[i];
    }

    sort(X_sum.begin(), X_sum.end());
    sort(Y_sum.begin(), Y_sum.end());

    // for (lng x : X_sum) 
    //     cout << x << ' ';
    // cout << endl;
    // for (lng y : Y_sum)
    //     cout << y << ' ';
    // cout << endl;

    lng ans = 0;
    int j = N;
    for (int i = 0; i <= N; i++) {
        while (X_sum[i] + Y_sum[j] > D && j >= 0)
            j--;

        if (j < 0)
            break;

        ans += j + 1;
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