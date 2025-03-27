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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
    
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n <= 2 || s == string(n, s[0])) {
        cout << s << endl;
        return;
    }
    
    map<char, int> cnts;
    for (char c : s)
        cnts[c]++;
    
    vector<pair<int, char>> V;
    for (auto &[k, v] : cnts) 
        V.pb({v, k});
    
    sort(V.begin(), V.end());
    
    vector<int> ord;
    for (int i = 0; i < n; i += 2) 
        ord.pb(i);
    for (int i = n - 1 - ((n - 1) % 2 == 0); i >= 0; i -= 2)
        ord.pb(i);
    
    // for (int x : ord)
    //     cout << x << ' ';
    // cout << endl;
    
    string ans(n, 'X');
    for (int i = 0; i < n; i++) {
        if (V.back().fi == 0)
            V.pop_back();
    
        ans[ord[i]] = V.back().se;
        V.back().fi--;
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