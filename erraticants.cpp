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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct Dijkstra {
    int n;
    vector<bool> is_proc;
    vector<lng> dis;
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unproc;

    Dijkstra(const vector<int> &src, int n, const vector<vector<pair<int, int>>> &adjl): n(n) {
        is_proc.resize(n + 1);
        dis.resize(n + 1, INF64);

        for (int u : src) {
            dis[u] = 0;
            unproc.push({dis[u], u});
        }
        while (!unproc.empty()) {
            int cur = unproc.top().se;
            unproc.pop();

            if (is_proc[cur]) {
                continue;
            }
            is_proc[cur] = true;

            for (auto [nxt, w] : adjl[cur]) {
                if (dis[cur] + w < dis[nxt]) {
                    dis[nxt] = dis[cur] + w;
                    unproc.push({dis[nxt], nxt});
                }
            }
        }
    }

    lng getMinDistance(int u) {
        return dis[u];
    }
};

void move(int &x, int &y, char d) {
    switch (d) {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
    }
}

void solve() {
    int n;
    cin >> n;

    int idx = 0;
    map<pair<int, int>, int> compress;
    compress[{0, 0}] = idx++;

    int x_prv = 0, y_prv = 0;
    vector<vector<pair<int, int>>> adjl(200);
    for (int i = 0; i < n; i++) {
        char d;
        cin >> d;

        int x_cur = x_prv, y_cur = y_prv;
        move(x_cur, y_cur, d);

        if (compress.find({x_cur, y_cur}) == compress.end())
            compress[{x_cur, y_cur}] = idx++;

        adjl[compress[{x_prv, y_prv}]].push_back({compress[{x_cur, y_cur}], 1});
        adjl[compress[{x_cur, y_cur}]].push_back({compress[{x_prv, y_prv}], 1});
    
        x_prv = x_cur;
        y_prv = y_cur;
    }

    Dijkstra djk({0}, n, adjl);

    cout << djk.getMinDistance(compress[{x_prv, y_prv}]) << endl;
    
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