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
    lng n, p, x_s, y_s, c, d;
    cin >> n >> p >> x_s >> y_s >> c >> d;
    vector<tuple<lng, lng, lng>> V(n);
    for (int i = 0; i < n; i++) {
        cin >> get<1>(V[i]) >> get<2>(V[i]);
        get<0>(V[i]) = get<1>(V[i]) + get<2>(V[i]);
    }

    sort(V.begin(), V.end(), greater<tuple<lng, lng, lng>>());

    for (int i = 0; i < p; i++) {
        x_s += get<1>(V[i]);
        y_s += get<2>(V[i]);
    }

    lng sum = x_s + y_s;
    cout << ((sum + 1) / 2) * (sum / 2) << endl;
    
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