// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct Dijkstra {
    int n;
    vector<bool> is_proc;
    vector<lng> dis;
    priority_queue<pair<lng, int>, vector<pair<lng, int>>, greater<pair<lng, int>>> unproc;

    Dijkstra(int n): n(n) {
        is_proc.resize(this->n + 1);
        dis.resize(this->n + 1, INF64);
    }

    void runDijkstra(const vector<int> &src, const vector<vector<pair<int, int>>> &adjl) {
        fill(is_proc.begin(), is_proc.end(), false);
        fill(dis.begin(), dis.end(), INF64);
        
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
        };

        return;
    }
};

void solve() {
    int n;
    cin >> n;
    lng sum = 0;
    vector<vector<pair<int, int>>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        sum += c;
        adjl[a].pb({b, c});
        adjl[b].pb({a, c});
    }

    Dijkstra djk(n);

    djk.runDijkstra({1}, adjl);

    int i_max = -1;
    lng max_dis = 0;
    for (int i = 1; i <= n; i++)
        if (djk.dis[i] > max_dis) {
            i_max = i;
            max_dis = djk.dis[i];
        }

    djk.runDijkstra({i_max}, adjl);

    max_dis = 0;
    for (int i = 1; i <= n; i++)
        max_dis = max(max_dis, djk.dis[i]);

    cout << 2 * sum - max_dis << endl;
    
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