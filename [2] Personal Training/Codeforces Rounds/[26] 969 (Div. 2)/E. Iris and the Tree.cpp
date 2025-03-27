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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int n;
lng w;
vector<vector<int>> adjl;

vector<int> travel_order;
void dfs(int cur, int prv) {
    travel_order.pb(cur);
    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        dfs(nxt, cur);
        travel_order.pb(cur);
    }

    return;
}

void solve() {
    cin >> n >> w;
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        adjl[p].pb(i);
        adjl[i].pb(p);
    }

    for (int i = 1; i <= n; i++)
        sort(adjl[i].begin(), adjl[i].end());

    travel_order.clear();
    dfs(1, 1);

    int j = 0;
    vector<int> edge_cnts(n + 1);
    vector<vector<int>> affected_by_edges(n + 1);
    for (int i = 0; i + 1 < travel_order.size(); i++) {
        j = max(j, travel_order[i]);
        edge_cnts[j]++;
        affected_by_edges[max(travel_order[i], travel_order[i + 1])].pb(j);
    }

    for (int i = 2; i <= n; i++)
        assert(affected_by_edges[i].size() == 2);

    int q = n - 1;
    int not_complete = n;
    lng insum = 0;
    while (q--) {
        int x;
        lng y;
        cin >> x >> y;

        w -= y;
        insum += 2 * y;
        edge_cnts[affected_by_edges[x][0]]--;
        if (edge_cnts[affected_by_edges[x][0]] == 0)
            not_complete--;
        edge_cnts[affected_by_edges[x][1]]--;
        if (edge_cnts[affected_by_edges[x][1]] == 0)
            not_complete--;

        cout << insum + w * not_complete << ' ';
    }
    cout << endl;

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