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

struct node {
    int depth = -1;

    // for longest path
    int prv = -1;
    int nxt = -1;
    
    int len = 1;
    lng ways = 0;
};

vector<node> memo;
vector<vector<int>> adjl;
void dfs(int cur, int depth) {
    memo[cur].depth = depth;
    for (int nxt : adjl[cur]) {
        dfs(nxt, depth + 1);

        if (memo[nxt].len + 1 > memo[cur].len) {
            memo[cur].nxt = nxt;
            memo[cur].len = memo[nxt].len + 1;
        }
        memo[cur].ways += memo[nxt].ways;
    }
    memo[cur].ways += memo[cur].len - 1;
    if (memo[cur].nxt != -1)
        memo[memo[cur].nxt].prv = cur;

    return;
}


void solve(int t) {
    int n;
    lng k;
    int q;
    cin >> n >> k >> q;
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;

        adjl[x].pb(i);
    }

    memo.clear();
    memo.resize(n + 1);
    dfs(1, 1);

    if (k <= memo[1].ways)
        cout << "YA" << endl;
    else {
        cout << "TIDAK" << endl;
        return;
    }

    if (q == 1) {
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 1; i <= n; i++)
            if (memo[i].prv == -1)
                pq.push({-memo[i].depth, memo[i].len, i});
        
        int l = 1;
        vector<int> ans(n + 1, -1);
        while (!pq.empty()) {
            auto [depth, len, cur] = pq.top();
            pq.pop();
            depth = abs(depth);

            // cout << depth << ' ' << len << ' ' << cur << endl;
        
            int r = l + len - 1;
            vector<int> sgmt = {cur};
            for (int i = 1; i < len; i++) {
                cur = memo[cur].nxt;
                sgmt.pb(cur);
            }

            // cout << "[" << l << ' ' << r << "]: ";
            // for (int x : sgmt)
            //     cout << x << ' ';
            // cout << endl;
            // cout << endl;

            int m = r;
            for (; m >= l; m--) {
                if (k == 0)
                    break;

                ans[sgmt[len - 1 - min<lng>(k, m - l)]] = m;
                k -= min<lng>(k, m - l);
            }

            m = l;
            for (int i = 0; i < len; i++) 
                if (ans[sgmt[i]] == -1) {
                    ans[sgmt[i]] = m;
                    m++;
                }

            l = r + 1;
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

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