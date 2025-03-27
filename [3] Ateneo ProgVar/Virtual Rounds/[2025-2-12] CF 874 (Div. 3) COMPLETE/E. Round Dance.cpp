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

void solve() {
    int n;
    cin >> n;
    vector<set<int>> adjl(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; 
        cin >> a;

        adjl[i].insert(a);
        adjl[a].insert(i);
    }

    UnionFind uf(n);
    for (int i = 1; i <= n; i++)
        for (int j : adjl[i])
            uf.uniteSets(i, j);

    map<int, vector<int>> G;
    for (int i = 1; i <= n; i++)
        G[uf.findSet(i)].pb(i);

    int cycle = 0, tree = 0;
    for (auto &[k, V] : G) {
        int cnt = 0;
        for (int &v : V) 
            cnt += (adjl[v].size() == 2);

        if (cnt == V.size()) 
            cycle++;
        else
            tree++;
    }

    // cout << "cycle: " << cycle << endl;
    // cout << "tree: " << tree << endl;
    cout << cycle + (tree > 0 ? 1 : 0) << ' ' << cycle + tree << endl;
    // cout << endl;
    
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