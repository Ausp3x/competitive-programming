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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct Dijkstra {
    int n;
    int t1, t2, st;
    vector<bool> is_proc;
    vector<lng> dis;
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unproc;

    Dijkstra(int n, int t1, int t2, int st, const vector<vector<tuple<int, lng, lng>>> &adjl): n(n), t1(t1), t2(t2), st(st) {
        is_proc.resize(n + 1);
        dis.resize(n + 1, INF64);

        dis[1] = st;
        unproc.push({st, 1});
        while (!unproc.empty()) {
            int cur = unproc.top().se;
            unproc.pop();

            if (is_proc[cur]) {
                continue;
            }
            is_proc[cur] = true;

            for (auto [nxt, l1, l2] : adjl[cur]) {
                lng new_dis = dis[cur] + l2;
                if (dis[cur] < t2 && dis[cur] + l1 > t1) {
                    new_dis = min(new_dis, t2 + l1);
                } else 
                    new_dis = dis[cur] + l1;

                if (new_dis < dis[nxt]) {
                    dis[nxt] = new_dis;
                    unproc.push({new_dis, nxt});
                }
            }
        }
    }

    lng getMinDistance(int v) {
        return dis[v];
    }

    void debugPrint() {
        cout << n << endl;
        cout << "is_proc: " << endl;
        for (bool x : is_proc) {
            cout << x << ' ';
        }
        cout << endl;
        cout << "dis: " << endl;
        for (lng x : dis) {
            cout << x << ' ';
        }
        cout << endl;

        return;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    // bus l, walk l
    vector<vector<tuple<int, lng, lng>>> adjl(n + 1);
    while (m--) {
        int u, v;
        lng l1, l2;
        cin >> u >> v >> l1 >> l2;

        adjl[u].pb({v, l1, l2});
        adjl[v].pb({u, l1, l2});
    }

    lng l = -1, r = 1000000001;
    while (r - l > 1) {
        lng md = (l + r) / 2;

        Dijkstra djk(n, t1, t2, md, adjl);

        if (djk.getMinDistance(n) <= t0)
            l = md;
        else
            r = md; 
    }

    cout << l << endl;
    
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