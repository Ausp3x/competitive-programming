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
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++)
        edges.pb({A[i], i});

    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 1; i--) {
        sort(edges.begin(), edges.end(), 
        [i](const pair<int, int> &p1, const pair<int, int> &p2) {
            return (p1.fi % i) < (p2.fi % i);
        });

        // cout << i << ": " << endl;
        // for (auto [x, y] : edges)
        //     cout << x % i << ' ' << y << endl;

        for (int j = 0; j + 1 < edges.size(); j++)
            if (edges[j].fi % i == edges[j + 1].fi % i) {
                ans.pb({edges[j].se, edges[j + 1].se});
                edges.erase(edges.begin() + j);
                break;
            }
    }

    reverse(ans.begin(), ans.end());

    cout << "YES" << endl;
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }

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