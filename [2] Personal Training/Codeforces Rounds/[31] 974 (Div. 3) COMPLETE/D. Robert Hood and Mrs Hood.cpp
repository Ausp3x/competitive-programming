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
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> in(n + 2);
    vector<int> V(n + 2);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        
        in[l]++;
        V[l]++;
        V[r + 1]--;
    }

    for (int i = 1; i < n + 2; i++) {
        in[i] += in[i - 1];
        V[i] += V[i - 1];
    }

    map<int, vector<int>> ans;
    // i, i + d - 1
    for (int i = 1; i < n - d + 2; i++) {
        int cnt = V[i] + in[i + d - 1] - in[i];
        ans[cnt].pb(i);
    }

    cout << ans.rbegin()->se[0] << ' ' << ans.begin()->se[0] << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}