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

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjl(n + 1);
    UnionFind uf_o(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].pb(v);
        adjl[v].pb(u);
        uf_o.uniteSets(u, v);
    }
    for (int i = 1; i <= n; i++)
        sort(adjl[i].begin(), adjl[i].end());

    // for (auto x : adjl) {
    //     for (int y : x)
    //         cout << y << ' ';
    //     cout << endl;
    // }

    int max_size = 0;
    bool is_all_lonely = true;
    vector<int> not_lonely;
    for (int i = 1; i <= n; i++) {
        int ii = uf_o.findSet(i);
        max_size = max(max_size, uf_o.size[ii]);
        if (uf_o.size[ii] > 2) {
            is_all_lonely = false;
            not_lonely.pb(i);
        } 
    }

    if (is_all_lonely) {
        lng ans = 0;
        for (int i = n; i >= 1; i--)
            ans += 1ll * i * (n - i + 1);

        cout << ans << endl;
        return;
    }

    if (not_lonely.size() == 3) {
        lng ans = 0;
        for (int i = n; i >= 1; i--)
            ans += 1ll * i * (n - i + 1);

        ans -= 3ll * not_lonely[0] * (n - not_lonely[2] + 1); 

        cout << ans << endl;
        return;
    }

    if (max_size == 3) {
        map<int, vector<int>> disjoint_sets;
        for (int i = 1; i <= n; i++)
            disjoint_sets[uf_o.findSet(i)].push_back(i);

        lng ans = 0;
        for (int i = n; i >= 1; i--)
            ans += 1ll * i * (n - i + 1);

        for (auto [k, v] : disjoint_sets) {
            if (v.size() < 3)
                continue;

            ans -= 3ll * v[0] * (n - v[2] + 1);
        }

        cout << ans << endl;
        return;
    }

    if (n <= 2000 && m <= 4000) {
        lng ans = 0;
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            UnionFind uf(n);
            for (int j = i; j <= n; j++) {
                cur++;
                for (int nxt : adjl[j]) {
                    if (nxt < i || nxt > j) {
                        continue;
                    }

                    int a = uf.findSet(j), b = uf.findSet(nxt);
                    int lonely_cnt = 0;
                    if (uf.size[a] <= 2)
                        lonely_cnt += uf.size[a];
                    if (uf.size[b] <= 2)
                        lonely_cnt += uf.size[b];

                    uf.uniteSets(a, b);
                    a = uf.findSet(a);

                    if (uf.size[a] > 2)
                        cur -= lonely_cnt;
                }

                ans += cur;       
            }        
        }

        cout << ans << endl;
        return;
    }

    bool subtask_8_chk = true;
    for (int i = 1; i <= n; i++) {
        if (adjl[i].size() > 2) {
            subtask_8_chk = false;
            break;
        }

        if (adjl[i].size() <= 1)
            continue;

        subtask_8_chk &= adjl[i][0] < i && i < adjl[i][1];
    }
 
    if (subtask_8_chk) {
        lng ans = 0;
        for (int i = 1; i <= n; i++) {
            lng l = 0, r = n + 1;
            if (adjl[i].empty()) {
                ans += (i - l) * (r - i);
                continue;
            }

            if (adjl[i].size() == 1) {
                if (adjl[i][0] < i)
                    l = max<lng>(l, adjl[i][0]);
                else 
                    r = min<lng>(r, adjl[i][0]);
            
                ans += (i - l) * (r - i);
                continue;
            }

            l = adjl[i][0];
            r = adjl[i][1];
            ans += (i - l) * (r - i);
        }

        for (int i = 1; i <= n; i++) {
            if (adjl[i].empty())
                continue;

            if (adjl[i].size() == 1)
                if (adjl[i][0] < i)
                    continue;

            int j = adjl[i].back();

            lng l = adjl[i].size() == 1 ? 0 : adjl[i][0]; 
            lng r = adjl[j].size() == 1 ? n + 1 : adjl[j][1];
            ans += 2 * (i - l) * (r - j);
        }

        cout << ans << endl;
        return;
    }

    vector<vector<int>> prvs(n + 1, vector<int>(2, 0));
    vector<vector<int>> nxts(n + 1, vector<int>(2, n + 1));
    for (int i = 1; i <= n; i++) {
        if (adjl[i].empty())
            continue;

        int l = -1, r = adjl[i].size();
        while (r - l > 1) {
            int md = (l + r) / 2;
            if (adjl[i][md] > i)
                r = md;
            else
                l = md;
        }

        if (l - 1 >= 0)
            prvs[i][1] = adjl[i][l - 1];
        if (l >= 0)
            prvs[i][0] = adjl[i][l];
        if (r < adjl[i].size())
            nxts[i][0] = adjl[i][r];
        if (r + 1 < adjl[i].size())
            nxts[i][1] = adjl[i][r + 1];
    }

    // for (int i = 1; i <= n; i++)
    //     cout << prvs[i][1] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << prvs[i][0] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << nxts[i][0] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << nxts[i][1] << ' ';
    // cout << endl;

    lng ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1ll * (i - prvs[i][0]) * (nxts[i][0] - i);
    for (int i = 1; i <= n; i++) {
        for (int j : adjl[i]) {
            if (j < i)
                continue;

            int lft_i = prvs[i][0], lft_j = (prvs[j][0] == i ? prvs[j][1] : prvs[j][0]);
            int rht_i = (nxts[i][0] == j ? nxts[i][1] : nxts[i][0]), rht_j = nxts[j][0];
            if (i < lft_j || rht_i < j)
                continue;
            
            ans += 2ll * (i - max(lft_i, lft_j)) * (min(rht_i, rht_j) - j);
        }
    }
    
    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}