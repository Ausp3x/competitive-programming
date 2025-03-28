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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        ans += a / 10;
    }

    // required increase, index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        if (A[i] == 100)
            continue;

        pq.push({10 - A[i] % 10, i});
    }

    while (k > 0) {
        if (pq.empty())
            break;

        if (k < pq.top().fi)
            break;

        auto [cur, idx] = pq.top();
        pq.pop();

        ans++;
        k -= cur;
        A[idx] += cur;

        if (A[idx] < 100)
            pq.push({10 - A[idx] % 10, idx});
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