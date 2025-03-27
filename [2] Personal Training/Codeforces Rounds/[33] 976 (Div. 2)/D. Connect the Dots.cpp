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

struct UnionFind {
    int n;
    vector<int> link, node_size, edge_size;

    UnionFind(int n): n(n) {
        link.resize(n + 1);
        iota(link.begin(), link.end(), 0);
        node_size.resize(n + 1, 1);
        edge_size.resize(n + 1);
    }

    int findSet(int u) {
        if (u == link[u]) {
            return link[u];
        }
            
        return link[u] = findSet(link[u]);
    }

    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    void uniteSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (node_size[a] < node_size[b]) {
            swap(a, b);
        }

        if (a == b) {
            edge_size[a]++;
            return;
        }

        node_size[a] += node_size[b];
        edge_size[a] += edge_size[b] + 1;
        link[b] = a;

        return;
    }
};

int D = 10;

void solve() {
    int n, m;
    cin >> n >> m;

    // d <= 10
    // a + d * k <= n
    vector<vector<int>> dp_add(D + 1, vector<int>(n + D + 1));
    vector<vector<int>> dp_min(D + 1, vector<int>(n + D + 1));
    while (m--) {
        int a, d, k;
        cin >> a >> d >> k;

        dp_add[d][a]++;
        dp_min[d][a + d * k + d]++;
    }

    UnionFind uf(n);

    for (int d = 1; d <= D; d++)
        for (int i = 1; i <= d; i++) {
            int cur = (dp_add[d][i] > 0 ? i : -1);
            for (int j = i + d; j <= n; j += d) {
                if (dp_add[d][j - d] - dp_min[d][j] == 0)
                    cur = -1;
                dp_add[d][j] += dp_add[d][j - d] - dp_min[d][j];

                if (dp_add[d][j] > 0) {
                    if (cur != -1)
                        uf.uniteSets(cur, j);
                    else
                        cur = j;
                } else 
                    cur = -1;
            }
        }

    set<int> ccs;
    for (int i = 1; i <= n; i++)
        ccs.insert(uf.findSet(i));

    cout << ccs.size() << endl;
    
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