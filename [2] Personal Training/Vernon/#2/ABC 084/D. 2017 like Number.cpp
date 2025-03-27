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

int N = 100'005;
vector<bool> is_prime(N, true);
indexed_set<int> similar;

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int li = similar.order_of_key(l);
        int ri = similar.order_of_key(r);

        if (*similar.find_by_order(ri) > r)
            ri--;

        cout << ri - li + 1 << endl; 
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (!is_prime[i])
            continue;
            
        for (lng j = lng(i) * i; j < N; j += i)
            is_prime[j] = false;
    }
    
    similar.insert(0);
    for (int i = 1; i < N; i += 2) 
        if (is_prime[i] && is_prime[(i + 1) / 2])
            similar.insert(i);
    similar.insert(INF32);
    
    // for (int x : similar)
    //     cout << x << ' ';
    // cout << endl;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}