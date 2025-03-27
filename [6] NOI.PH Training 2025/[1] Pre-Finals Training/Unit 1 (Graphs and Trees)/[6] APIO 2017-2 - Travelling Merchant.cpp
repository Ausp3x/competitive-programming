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

struct FloydWarshall {
    int n;
    vector<vector<lng>> dis;
    
    FloydWarshall(int n, vector<vector<lng>> dis) : n(n), dis(dis) {
        assert(this->dis.size() == this->n + 1);
        for (int i = 0; i <= this->n; i++) {
            assert(this->dis[i].size() == this->n + 1);
        }
    }
    
    void runFloydWarshall(int bgn, int end) {
        assert(0 <= bgn && bgn <= n);
        assert(0 <= end && end <= n);

        for (int k = bgn; k <= end; k++) {
            for (int i = bgn; i <= end; i++) {
                for (int j = bgn; j <= end; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
                }
            }
        }
    
        return;
    }
};

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<lng>> B(n + 1, vector<lng>(x + 1)), S(n + 1, vector<lng>(x + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++)
            cin >> B[i][j] >> S[i][j];
    vector<vector<lng>> adjm(n + 1, vector<lng>(n + 1, INF64));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjm[u][v] = w;
    }

    FloydWarshall fw1(n, adjm);
    fw1.runFloydWarshall(1, n);

    vector<vector<lng>> profit(n + 1, vector<lng>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= x; k++) 
                if (B[i][k] != -1 && S[j][k] != -1)
                    profit[i][j] = max(profit[i][j], S[j][k] - B[i][k]); 

    lng l = 0, r = 1'000'000'001;
    while (r - l > 1) {
        lng md = (l + r) / 2;
            
        vector<vector<lng>> adjm2(n + 1, vector<lng>(n + 1, INF64));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adjm2[i][j] = md * min(fw1.dis[i][j], INF64 / md) - profit[i][j];

        FloydWarshall fw2(n, adjm2);
        fw2.runFloydWarshall(1, n);

        bool has_nonnegative_cycle = false;
        for (int i = 1; i <= n; i++)
            if (fw2.dis[i][i] <= 0)
                has_nonnegative_cycle = true;

        if (has_nonnegative_cycle)
            l = md;
        else
            r = md;
    }

    cout << l << endl;

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