// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> A(k, vector<int>(n));
    for (int i = 0; i < k; i++)
        for (int &a : A[i])
            cin >> a;

    if (n == 2 || k == 1) {
        cout << "YES" << endl;
        return;
    }

    map<int, int> idxs;
    for (int i = 1; i < n; i++)
        idxs[A[0][i]] = i;

    for (int i = 1; i < k; i++) {
        int prv = (A[i][1] == A[0][0] ? 2 : 1);
        for (int cur = prv + 1; cur < n; cur++) {
            if (A[i][cur] == A[0][0])
                continue;
            
            if (idxs[A[i][prv]] > idxs[A[i][cur]]) {
                cout << "NO" << endl;
                return;
            }
            
            prv = cur;
        }
    }
   
    vector<vector<bool>> vst(2, vector<bool>(n + 1));
    for (int i = 1; i < k; i++) {
        bool chk = false;
        for (int j = 1; j < n; j++) {
            if (A[i][j] == A[0][0]) {
                chk = true;
                continue;
            }

            vst[chk][A[i][j]] = true;
        }
    }

    for (int i = 1; i <= n; i++)
        if (vst[0][i] && vst[1][i]) {
            cout << "NO" << endl;
            return;
        }

    vector<bool> vst2;
    for (int i = 1; i < n; i++) {
        if (!vst[0][A[0][i]] && !vst[1][A[0][i]])
            continue;
        
        vst2.pb(vst[1][A[0][i]]);
    }
    
    // for (bool x : vst2)
    //     cout << x << ' ';
    // cout << endl;

    for (int i = 0; i < vst2.size() - 1; i++)
        if (vst2[i] == 1 && vst2[i + 1] == 0) {
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << endl;
    }

    return 0;
}