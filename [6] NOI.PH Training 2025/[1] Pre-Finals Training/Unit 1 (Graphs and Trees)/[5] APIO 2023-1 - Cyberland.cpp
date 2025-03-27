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

double solve(int N, int M, int K, int H, vector<int> x, vector<int> y, vector<int> c, vector<int> arr) {
    K = min(K, 72);

    UnionFind uf(N);
    vector<vector<pair<int, int>>> adjl(N);
    for (int i = 0; i < M; i++) {
        if (x[i] != H && y[i] != H)
            uf.uniteSets(x[i], y[i]);

        adjl[x[i]].pb({y[i], c[i]});
        adjl[y[i]].pb({x[i], c[i]});
    }

    vector<double> neg_pow2(K + 1);
    neg_pow2[0] = 1;
    for (int i = 1; i <= K; i++)
        neg_pow2[i] = neg_pow2[i - 1] / 2;

    arr[0] = 0;
    vector<vector<double>> dis(K + 1, vector<double>(N, INF64));
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
    
    auto proc = [&](int k, int x, double d) {
        if (dis[k][x] > d) {
            dis[k][x] = d;
            pq.push({d, k, x});
        }

        return;
    };

    proc(K, H, 0);
    while (!pq.empty()) {
        auto [d, k, u] = pq.top();
        pq.pop();

        if (dis[k][u] < d)
            continue;

        if (arr[u] == 0)
            return d;
        
        for (auto &[v, c] : adjl[u]) {
            if (!uf.isSameSet(v, 0))
                continue;

            proc(k, v, d + c * neg_pow2[K - k]);
            if (arr[u] == 2 && k > 0)
                proc(k - 1, v, d + c * neg_pow2[K - k + 1]);
        }
    }
    
    return -1;
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cout << solve(3, 2, 30, 2, {1, 2}, {2, 0}, {12, 4}, {1, 2, 1}) << endl;
//     cout << solve(4, 4, 30, 3, {0, 0, 1, 2}, {1, 2, 3, 3}, {5, 4, 2, 4}, {1, 0, 2, 1}) << endl;

//     return 0;
// }