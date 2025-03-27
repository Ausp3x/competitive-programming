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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct Point {
    int i, j;

    bool operator<(const Point &rhs) const {
        return tie(i, j) < tie(rhs.i, rhs.j);
    }
    
    Point(int i, int j): i(i), j(j) {}
};

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    
    int N = 1'000'000;
    vector<vector<Point>> facs(N + 1);
    for (int i = 1; i * i <= N; i++) 
        for (int j = i; i * j <= N; j++) {
            if (i <= n && j <= m)
                facs[i * j].pb({i, j});
            if (i != j && i <= m && j <= n)
                facs[i * j].pb({j, i});
        }

    map<int, bool> p_vst;
    map<Point, bool> vst;
    queue<Point> q;
    q.push(Point(1, 1));
    vst[Point(1, 1)] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int i = cur.i, j = cur.j, p = grid[i][j];
        if (p_vst[p])
            continue;
        p_vst[p] = true;

        for (auto nxt : facs[p]) {
            if (nxt.i > n || nxt.j > m) 
                continue;
            
            q.push(nxt);
            vst[nxt] = true;
        }
    }
    
    cout << (vst[Point(n, m)] ? "yes" : "no");

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