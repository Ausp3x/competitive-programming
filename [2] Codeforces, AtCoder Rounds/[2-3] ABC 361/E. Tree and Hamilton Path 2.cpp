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
    int N;
    cin >> N;
    lng edge_sum = 0;
    vector<vector<pair<int, int>>> adjl(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;

        edge_sum += C;
        adjl[A].push_back({B, C});
        adjl[B].push_back({A, C});
    }

    vector<lng> dis(N, -1);
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto [nxt, cst] : adjl[cur]) {
            if (dis[nxt] != -1)
                continue;

            dis[nxt] = dis[cur] + cst;
            q.push(nxt);
        }
    }

    // for (lng x : dis)
    //     cout << x << ' ';
    // cout << endl;

    lng d_max = -1;
    int d_max_i = -1;
    for (int i = 0; i < N; i++)
        if (dis[i] > d_max) {
            d_max = dis[i];
            d_max_i = i;
        }

    dis.clear();
    dis.resize(N, -1);
    dis[d_max_i] = 0;
    q.push(d_max_i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto [nxt, cst] : adjl[cur]) {
            if (dis[nxt] != -1)
                continue;

            dis[nxt] = dis[cur] + cst;
            q.push(nxt);
        }
    }

    lng ans = -1;
    for (int i = 0; i < N; i++)
        ans = max(ans, dis[i]);

    cout << 2 * edge_sum - ans << endl;

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