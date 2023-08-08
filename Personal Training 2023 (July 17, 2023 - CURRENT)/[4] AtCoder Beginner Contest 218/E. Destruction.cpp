// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

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
    lng ans = 0;
    vector<tuple<int, int, int>> edjl(m);
    for (auto &[c, a, b] : edjl) {
        cin >> a >> b >> c;
        ans += c;
    }

    sort(edjl.begin(), edjl.end());

    UnionFind u(n);
    for (auto &[c, a, b] : edjl) { 
        if (c <= 0) {
            u.uniteSets(a, b);
            ans -= c;
            continue;
        }

        if (u.size[u.findSet(1)] == n) {
            break;
        }

        if (!u.sameSet(a, b)) {
            u.uniteSets(a, b);
            ans -= c;
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}