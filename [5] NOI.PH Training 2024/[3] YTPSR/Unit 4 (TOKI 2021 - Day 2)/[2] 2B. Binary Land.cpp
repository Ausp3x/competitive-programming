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
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    vector<int> B(n);
    for (int &b : B)
        cin >> b;

    vector<vector<int>> P(30), Q(30);
    for (int i = 0; i < n; i++) {
        bool leading_bit_found = false;
        for (int j = 29; j >= 0; j--) {
            if (A[i] & (1 << j)) {
                if (!leading_bit_found) {
                    P[j].pb(i);
                    leading_bit_found = true;
                }
            } else {
                if (leading_bit_found)
                    Q[j].pb(i);
            }
        }
    }

    UnionFind uf(n);
    for (int i = 0; i < 30; i++) {
        if (P[i].empty() || Q[i].empty())
            continue;
        
        for (int j = 0; j < Q[i].size(); j++) {
            if (P[i][0] == Q[i][j])
                continue;
            
            uf.uniteSets(P[i][0], Q[i][j]);
        }

        for (int j = 0; j < P[i].size(); j++) {
            if (Q[i][0] == P[i][j])
                continue;
            
            uf.uniteSets(Q[i][0], P[i][j]);
        }
    }

    map<int, lng> M;
    for (int i = 0; i < n; i++) {
        int is = uf.findSet(i);
        M[is] += B[i]; 
    }

    for (int i = 0; i < n; i++) 
        cout << M[uf.findSet(i)] << endl;
    cout << endl;

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