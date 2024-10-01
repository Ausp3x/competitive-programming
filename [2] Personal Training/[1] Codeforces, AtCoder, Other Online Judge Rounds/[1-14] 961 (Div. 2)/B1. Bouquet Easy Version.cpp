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
    lng m;
    cin >> n >> m;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    
    sort(A.begin(), A.end());

    // for (int x : A)
    //     cout << x << ' ';
    // cout << endl;

    vector<lng> A_sum(n + 1);
    for (int i = 1; i <= n; i++)
        A_sum[i] = A_sum[i - 1] + A[i];

    int j = 1;
    lng ans = 0;
    for (int i = 1; i <= n; i++) {
        j = max(j, i);
        while (j + 1 <= n) {
            if (A[j + 1] - A[i] <= 1 && A_sum[j + 1] - A_sum[i - 1] <= m)
                j++;
            else
                break;
        }

        // cout << i << ' ' << j << endl;
        
        if (A_sum[j] - A_sum[i - 1] <= m)
            ans = max(ans, A_sum[j] - A_sum[i - 1]);
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