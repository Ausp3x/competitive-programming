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
    int n, k;
    cin >> n >> k;
    vector<vector<string>> preferences(n);
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        
        preferences[i].resize(q);
        for (auto &s : preferences[i])  
            cin >> s;
        reverse(preferences[i].begin(), preferences[i].end());
    }
    int p;
    cin >> p;
    vector<string> performances(p);
    for (auto &s : performances)
        cin >> s;
    reverse(performances.begin(), performances.end());

    map<string, bool> is_picked;
    vector<vector<string>> ans(n);
    for (int j = 0; j < k; j++) 
        for (int i = 0; i < n; i++) {
            while (!preferences[i].empty() && is_picked[preferences[i].back()])
                preferences[i].pop_back();
            while (!performances.empty() && is_picked[performances.back()])
                performances.pop_back();
            
            if (!preferences[i].empty()) {
                is_picked[preferences[i].back()] = true;
                ans[i].pb(preferences[i].back());
                preferences[i].pop_back();
            } else {
                is_picked[performances.back()] = true;
                ans[i].pb(performances.back());
                performances.pop_back();
            }
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cout << ans[i][j] << ' ';
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
        solve();
    }

    return 0;
}