// 人外有人，天外有天
// author: Ausp3x
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;
 
int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;
 
int const MOD = 1000000007;
 
int n, m;
vector<vector<int>> adjl(20);
vector<vector<int>> memo(20, vector<int>(1 << 20, -1));
 
inline int countHamiltonianPaths(int cur, int vst) {
    if (memo[cur][vst] != -1) {
        return memo[cur][vst];
    }
 
    int cnt = 0;
    for (int nxt : adjl[cur]) {
        if (nxt == cur || !(vst & (1 << nxt))) {
            continue;
        }
 
        cnt += countHamiltonianPaths(nxt, vst ^ (1 << cur));
        cnt %= MOD;
    }
 
    memo[cur][vst] = cnt;
    
    return cnt;
}
 
 
void solve() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        
        u--; 
        v--;
        adjl[u].push_back(v);
    }
 
    memo[n - 1][1 << (n - 1)] = 1;
 
    cout << countHamiltonianPaths(0, (1 << n) - 1) << endl;
    
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