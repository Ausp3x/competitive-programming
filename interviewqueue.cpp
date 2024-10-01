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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> V(n + 2);
    map<int, int> cnts;
    V[0] = -1;
    V[n + 1] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
        cnts[V[i]]++;
    }

    set<int> changed;
    vector<array<int, 2>> LR(n + 2, {-1, -1});
    LR[0][1] = 1;
    LR[n + 1][0] = n;
    for (int i = 1; i <= n; i++) {
        changed.insert(i);
        LR[i][0] = i - 1;
        LR[i][1] = i + 1;
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        vector<int> cur;
        for (int x : changed)
            if (V[LR[x][0]] > V[x] || V[LR[x][1]] > V[x])
                cur.pb(x);

        if (cur.empty())
            break;
        
        ans.pb({});

        set<int> new_changed;
        for (int x : cur) {
            ans.back().pb(V[x]);
            if (LR[x][0] > 0)
                new_changed.insert(LR[x][0]);
            if (LR[x][1] < n + 1)
                new_changed.insert(LR[x][1]);
            LR[LR[x][0]][1] = LR[x][1];
            LR[LR[x][1]][0] = LR[x][0];
        }

        for (int x : cur) 
            if (new_changed.find(x) != new_changed.end())
                new_changed.erase(x);
        
        changed = new_changed;
    }

    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        for (int x : ans[i])
            cout << x << ' ';
        cout << endl;
    }
    auto [v_max, v_max_cnt] = *cnts.rbegin();
    for (int i = 0; i < v_max_cnt; i++)
        cout << v_max << ' ';
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