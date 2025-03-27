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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct UnionFind {
    int n;
    vector<int> link, node_size, edge_size;

    void init(int n) {
        this->n = n;
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

int N, E = 0;
int simple_cycle_size = -1;
vector<int> edg_cnts;
vector<vector<int>> adjl;
UnionFind uf_all;

vector<vector<int>> cands_edg_cnts(4);
vector<UnionFind> uf_cands(4);

void Init(int n) {
    N = n;
    edg_cnts.resize(n);
    adjl.resize(n);
    uf_all.init(n);
    for (int i = 0; i < 4; i++)
        cands_edg_cnts[i].resize(n);
    for (int i = 0; i < 4; i++)
        uf_cands[i].init(n);

    return;
}

bool is_impossible = false;
vector<bool> is_pos_cands(4, true);
vector<int> idxs(4);

void Link(int a, int b) {
    if (edg_cnts[a] < edg_cnts[b])
        swap(a, b);

    edg_cnts[a]++;
    edg_cnts[b]++;
    adjl[a].pb(b);
    adjl[b].pb(a);

    if (edg_cnts[a] > E && edg_cnts[a] == 3) {
        E = edg_cnts[a];
        uf_all.uniteSets(a, b);

        assert(adjl[a].size() == 3);

        idxs[0] = a;
        for (int i = 0; i < 3; i++) 
            idxs[i + 1] = adjl[a][i];

        // for (int x : idxs)
        //     cout << x << ' ';
        // cout << endl;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < N; j++) {
                if (j == idxs[i])
                    continue;
                
                for (int k : adjl[j]) {
                    if (k == idxs[i])
                        continue;

                    if (k < j)
                        continue;

                    cands_edg_cnts[i][j]++;
                    cands_edg_cnts[i][k]++;
                    if (cands_edg_cnts[i][j] >= 3 || cands_edg_cnts[i][k] >= 3)
                        is_pos_cands[i] = false;

                    if (uf_cands[i].findSet(j) == uf_cands[i].findSet(k))
                        is_pos_cands[i] = false;
                    uf_cands[i].uniteSets(j, k);
                }
            }
        }

        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < N; j++)
        //         cout << cands_edg_cnts[i][j] << ' ';
        //     cout << endl;
        // }

        bool has_candidates = false;
        for (int i = 0; i < 4; i++)
            has_candidates |= is_pos_cands[i];

        if (!has_candidates)
            is_impossible = true;
        
        // cout << is_impossible << endl;

        return;
    }

    E = max(E, edg_cnts[a]);

    if (E == 2 && uf_all.findSet(a) == uf_all.findSet(b)) {
        uf_all.uniteSets(a, b);
        
        if (simple_cycle_size != -1) {
            is_impossible = true;
            return;
        }

        simple_cycle_size = uf_all.node_size[uf_all.findSet(a)];
        return;
    }

    uf_all.uniteSets(a, b);

    if (E >= 3) {
        for (int i = 0; i < 4; i++) {
            if (idxs[i] == a || idxs[i] == b)
                continue;

            cands_edg_cnts[i][a]++;
            cands_edg_cnts[i][b]++;
            if (cands_edg_cnts[i][a] >= 3 || cands_edg_cnts[i][b] >= 3)
                is_pos_cands[i] = false;

            if (uf_cands[i].findSet(a) == uf_cands[i].findSet(b))
                is_pos_cands[i] = false; 
            uf_cands[i].uniteSets(a, b);
        }

        bool has_candidates = false;
        for (int i = 0; i < 4; i++)
            has_candidates |= is_pos_cands[i];

        if (!has_candidates)
            is_impossible = true;

        return;
    }

    return;
}

int CountCritical() {
    if (is_impossible)
        return 0;

    if (E <= 1)
        return N;
    
    if (E == 2)
        return (simple_cycle_size == -1 ? N : simple_cycle_size);

    return accumulate(is_pos_cands.begin(), is_pos_cands.end(), 0);
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        Init(n);
        while (l--) {
            int a;
            cin >> a;

            if (a == -1) {
                cout << CountCritical() << endl;
                continue;
            }

            int b;
            cin >> b;
            Link(a, b);
        }
    }

    return 0;
}
#endif