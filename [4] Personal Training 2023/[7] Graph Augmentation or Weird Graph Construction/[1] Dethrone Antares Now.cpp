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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adjl(2 * n + 2);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adjl[2 * u].push_back(2 * v + 1);
        adjl[2 * u + 1].push_back(2 * v);
        adjl[2 * v].push_back(2 * u + 1);
        adjl[2 * v + 1].push_back(2 * u);
    }
    vector<int> cmdr_planets(k);
    for (int &x : cmdr_planets) {
        cin >> x;
    }

    vector<vector<int>> dis(n + 1), prv(n + 1);
    for (int x : cmdr_planets) {
        dis[x].resize(2 * n + 2, INF32);
        prv[x].resize(2 * n + 2, -1);
        queue<int> q;
        dis[x][2 * x] = 0;
        q.push(2 * x);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjl[u]) {
                if (dis[x][v] != INF32) {
                    continue;
                }

                dis[x][v] = dis[x][u] + 1;
                prv[x][v] = u;
                q.push(v);
            }
        }
    }

    int min_dis = INF32, end = -1;
    for (int i = 1; i <= n; i++) {
        int evn_dis = 0, odd_dis = 0; 
        for (int x : cmdr_planets) {
            evn_dis = max(evn_dis, dis[x][2 * i]);
            odd_dis = max(odd_dis, dis[x][2 * i + 1]);
        }

        if (evn_dis < min_dis) {
            min_dis = evn_dis;
            end = 2 * i;
        }
    
        if (odd_dis < min_dis) {
            min_dis = odd_dis;
            end = 2 * i + 1;
        }        
    }

    if (min_dis == INF32) {
        cout << "DAN'T" << endl;
        return;
    }

    cout << "DAN" << endl;
    cout << min_dis << endl;
    for (int x : cmdr_planets) {
        int end_tmp = end;
        vector<int> ans;
        ans.push_back(end_tmp / 2);
        while (end_tmp != 2 * x) {
            end_tmp = prv[x][end_tmp];
            ans.push_back(end_tmp / 2);
        }

        ans.pop_back();
        reverse(ans.begin(), ans.end());

        while (int(ans.size()) < min_dis) {
            ans.push_back(adjl[end][0] / 2);
            ans.push_back(end / 2);
        }

        for (int y : ans) {
            cout << y << ' ';
        }
        cout << endl;
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