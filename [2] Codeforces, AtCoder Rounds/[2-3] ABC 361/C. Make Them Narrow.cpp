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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &a : A)
        cin >> a;

    if (N == 2) {
        cout << 0 << endl;
        return;
    }

    sort(A.begin(), A.end());

    // for (int a : A)
    //     cout << a << ' ';
    // cout << endl;

    lng ans = INF32;
    for (int i = 0; i <= K; i++)
        ans = min<lng>(ans, A[i + N - K - 1] - A[i]);
    
    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}