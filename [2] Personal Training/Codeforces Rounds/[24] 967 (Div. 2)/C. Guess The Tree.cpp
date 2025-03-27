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

struct UnionFind {
    int n;
    vector<int> link, node_size, edge_size;

    UnionFind(int n): n(n) {
        link.resize(n + 1);
        iota(link.begin(), link.end(), 0);
        node_size.resize(n + 1, 1);
        edge_size.resize(n + 1);
    }

    int findSet(int v) {
        if (v == link[v]) {
            return link[v];
        }
            
        return link[v] = findSet(link[v]);
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

    void debugPrint() {
        cout << n << endl;
        cout << "link:" << endl;
        for (int x : link)
            cout << x << ' ';
        cout << endl;
        cout << "node_size:" << endl;
        for (int x : node_size)
            cout << x << ' ';
        cout << endl;
        cout << "edge_size:" << endl;
        for (int x : edge_size)
            cout << x << ' ';
        cout << endl;

        return;
    }
};

int n;
vector<vector<int>> memo;
set<pair<int, int>> edges;
void dp(int a, int b, UnionFind &uf) {
    if (memo[a][b] != -1 || uf.isSameSet(a, b))
        return;
    
    cout << "? " << a << ' ' << b << endl;
    cin >> memo[a][b];
    assert(memo[a][b] != -1);

    if (memo[a][b] == a) {
        edges.insert({min(a, b), max(a, b)});
        uf.uniteSets(a, b);
        return;
    }

    dp(a, memo[a][b], uf);
    dp(memo[a][b], b, uf);

    return;
}

void solve() {
    cin >> n;
    
    memo.clear();
    memo.resize(n + 1, vector<int>(n + 1, -1));
    edges.clear();
    UnionFind uf(n);

    for (int i = 2; i <= n; i++)
        dp(1, i, uf);

    assert(edges.size() == n - 1);
    cout << "! ";
    for (auto &[a, b] : edges)
        cout << a << ' ' << b << ' ';
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