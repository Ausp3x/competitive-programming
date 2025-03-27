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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int const MOD = 1'000'000'007;

void solve() {
    lng n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n % MOD << endl;
        return;
    }

    lll m = -1;
    lng f_1 = 1, f_2 = 1;
    for (int i = 3; i <= 10'000'000; i++) {
        lng f_3 = (f_1 + f_2) % k;
        
        if (f_3 == 0) {
            m = i;
            break;
        }
    
        f_1 = f_2;
        f_2 = f_3;
    }
    
    cout << lng(n * m % MOD) << endl;
    
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