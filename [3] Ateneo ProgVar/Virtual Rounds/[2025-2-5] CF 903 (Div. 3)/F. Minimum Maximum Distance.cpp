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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<bool> is_selected(n + 1);
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;

        is_selected[a] = true;
    }
    vector<set<int>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].insert(v);
        adjl[v].insert(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (adjl[i].size() == 1)
            q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (is_selected[cur])
            continue;

        int nxt = *adjl[cur].begin();
        adjl[cur].clear();
        adjl[nxt].erase(cur);

        if (adjl[nxt].size() == 1)
            q.push(nxt);
    }

    int bgn = -1;
    for (int i = 1; i <= n; i++) 
        if (!adjl[i].empty()) {
            bgn = i;
            break;
        }

    if (bgn == -1) {
        cout << 0 << endl;
        return;
    }

    int end = -1, mx_dis = -1;
    queue<pair<int, int>> bfs;
    vector<bool> vst(n + 1);
    bfs.push({bgn, 0});
    vst[bgn] = true;
    while (!bfs.empty()) {
        auto [cur, dis] = bfs.front();
        bfs.pop();

        if (dis > mx_dis) {
            end = cur;
            mx_dis = dis;
        }

        for (int nxt : adjl[cur]) {
            if (vst[nxt])
                continue;

            bfs.push({nxt, dis + 1});
            vst[nxt] = true;
        }
    }

    bgn = end;
    end = -1;
    mx_dis = -1;
    vst.clear();
    vst.resize(n + 1);
    bfs.push({bgn, 0});
    vst[bgn] = true;
    while (!bfs.empty()) {
        auto [cur, dis] = bfs.front();
        bfs.pop();

        if (dis > mx_dis) {
            end = cur;
            mx_dis = dis;
        }

        for (int nxt : adjl[cur]) {
            if (vst[nxt])
                continue;

            bfs.push({nxt, dis + 1});
            vst[nxt] = true;
        }
    }

    cout << (mx_dis + 1) / 2 << endl;

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