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
    vector<pair<lng, lng>> V(n);
    for (auto &[d, a] : V) 
        cin >> d >> a;
    V.pb({INF64, INF64});
    
    lng ans = 0, cur = 0;
    stack<pair<lng, lng>> S;
    for (int i = 0; i < n; i++) {
        auto [d_cur, a_cur] = V[i];
        lng d_nxt = V[i + 1].fi;
    
        S.push(V[i]);
    
        // [d_cur, d_nxt)
        lng available = 0;
        while (!S.empty()) {
            lng cur = d_cur + available / m; 
            if (cur == d_nxt)
                break;
    
            lng lim = min(S.top().fi + k - 1, d_nxt - 1);           
            if (lim < cur) {
                S.pop();
                continue;
            }
            
            lng req = m * (lim - d_cur + 1);
            if (available + S.top().se <= req) {
                available += S.top().se;
                S.pop();
            } else {
                lng extra = max(req - available, 0ll);
                available += extra;
                S.top().se -= extra;
            }
        }
    
        ans += available / m;
    }
    
    cout << ans << endl;
    
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