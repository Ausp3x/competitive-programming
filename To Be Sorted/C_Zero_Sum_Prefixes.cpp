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
    
void solve() {
    int n;
    cin >> n;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;
    
    int ans = 0, min_zero_idx = -1;
    lng cur = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            min_zero_idx = i;
            break;
        }
        
        cur += A[i];
        if (cur == 0)
            ans++;        
    }
    
    if (min_zero_idx == -1) {
        cout << ans << endl;
        return;
    }
    
    vector<int> zero_idxs;
    for (int i = 0; i < n; i++)
        if (A[i] == 0)
            zero_idxs.pb(i);
    zero_idxs.pb(n);

    for (int i = 0; i < zero_idxs.size() - 1; i++) {
        cur = 0;
        int max_cur = 0;
        map<lng, int> cnts;
        for (int j = zero_idxs[i]; j < zero_idxs[i + 1]; j++) {
            cur += A[j];
            cnts[cur]++;
            max_cur = max(max_cur, cnts[cur]);
        }

        ans += max_cur;
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