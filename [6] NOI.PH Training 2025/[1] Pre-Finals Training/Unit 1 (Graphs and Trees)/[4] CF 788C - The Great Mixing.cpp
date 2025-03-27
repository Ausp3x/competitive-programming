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

int N = 2001;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> A_set;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;

        A_set.insert(a - n);
    }

    vector<int> A;
    for (int a : A_set)    
        A.pb(a);

    vector<vector<bool>> vst(2, vector<bool>(N));
    vst[0][1000] = true;
    for (int i = 0; i < 1000; i++) {
        int i_cur = i & 1, i_nxt = i_cur ^ 1;
        for (int j = 0; j < N; j++)
            vst[i_nxt][j] = false;

        for (int j = 0; j < N; j++) { 
            if (!vst[i_cur][j])
                continue;
            
            for (int a : A) {
                if (j + a < 0 || N <= j + a)
                    continue;

                vst[i_nxt][j + a] = true;
            }
        }

        if (vst[i_nxt][1000]) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << -1 << endl;

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