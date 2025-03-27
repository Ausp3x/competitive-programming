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
    int n, m, k;
    cin >> n >> m >> k;
    
    map<int, int> M;
    vector<vector<pair<int, double>>> ans(k);
    int cnt = 1, rem_milk = m * k;
    for (int i = 0; i < k; i++) {
        int need_cup = n * m;
        while (need_cup > 0) {
            if (rem_milk > 0) {
                int used = min(rem_milk, need_cup);
                rem_milk -= used;
                need_cup -= used;
                
                M[cnt]++;
                ans[i].pb({cnt, double(used) / k});
            } else {
                cnt++;
                rem_milk = m * k;
            }
        }
    }

    for (auto &[k, v] : M) 
        if (v > 2) {
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
    for (auto A : ans) {
        for (auto &[a, b] : A) {
            cout << a << ' ';
            cout << setprecision(15) << b << ' ';
        }
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