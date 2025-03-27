// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

struct UnionFind {
    int n;
    vector<int> link, size;

    UnionFind(int n): n(n), link(n + 1), size(n + 1, 1) {
        iota(link.begin(), link.end(), 0);
    }

    int findSet(int v) {
        if (v == link[v]) {
            return link[v];
        } else {
            return link[v] = findSet(link[v]);
        }
    }

    bool sameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    void uniteSets(int a, int b) {
        if (sameSet(a, b)) {
            return;
        }

        a = findSet(a);
        b = findSet(b);
        
        if (size[a] < size[b]) {
            swap(a, b);
        }
        
        size[a] += size[b];
        link[b] = a;

        return;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjl(n + 1);
    UnionFind u(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        adjl[a].push_back(b);
        adjl[b].push_back(a);

        if (adjl[a].size() > 2 || adjl[b].size() > 2) {
            cout << "No" << endl;

            return;
        }

        if (u.sameSet(a, b)) {
            cout << "No" << endl;

            return;
        } 

        u.uniteSets(a, b);
    }

    cout << "Yes" << endl;
    
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