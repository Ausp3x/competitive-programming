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
    int n, q;
    cin >> n >> q;
    vector<lng> X(n);
    for (lng &x : X)
        cin >> x;
    vector<lng> K(q);
    for (lng &k : K)
        cin >> k;

    map<lng, lng> M;
    lng cur = 0, cnt = n - 1;
    for (int i = 0; i < n; i++) {
        cur += cnt;
        M[cur]++;
        if (i + 1 < n) {
            cur -= n - cnt - 1;
            M[cur] += X[i + 1] - X[i] - 1;
        }

        cnt--;
    }

    for (int i = 0; i < q; i++)
        cout << M[K[i]] << ' ';
    cout << endl;
    
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