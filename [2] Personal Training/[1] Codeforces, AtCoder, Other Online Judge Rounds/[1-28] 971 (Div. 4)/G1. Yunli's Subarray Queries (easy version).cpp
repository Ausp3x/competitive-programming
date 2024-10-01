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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    
    map<int, int> cnts;
    set<pair<int, int>> S;
    vector<int> ans(n - k + 2);
    for (int i = 1; i <= k; i++)
        cnts[A[i] - i]++;
    for (auto &[a, b] : cnts)
        S.insert({b, a});
    ans[1] = k - S.rbegin()->first; 
    for (int i = k + 1; i <= n; i++) {
        int l = A[i - k] - i + k, r = A[i] - i;
    
        if (S.find({cnts[l], l}) != S.end())
            S.erase({cnts[l], l});
        if (S.find({cnts[r], r}) != S.end())
            S.erase({cnts[r], r});
    
        cnts[l]--;
        cnts[r]++;        
    
        S.insert({cnts[l], l});
        S.insert({cnts[r], r});
    
        ans[i - k + 1] = k - S.rbegin()->first;
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
    
        cout << ans[l] << endl;
    }
    
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