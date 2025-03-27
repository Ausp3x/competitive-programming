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

mt19937_64 rng_lng(chrono::steady_clock::now().time_since_epoch().count());
lng randLng(lng l, lng r) {
    return uniform_int_distribution<lng>(l, r)(rng_lng);
}

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> A_unique;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        
        A_unique.insert(A[i]);
    }

    map<int, lng> A_hashes;
    for (int a : A_unique)
        A_hashes[a] = randLng(0, 2 * INF64);

    vector<lng> A_xor(n + 1);
    for (int i = 1; i <= n; i++) {
        A_xor[i] = A_hashes[A[i]];
        A_xor[i] ^= A_xor[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        if ((r - l + 1) % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << (A_xor[r] ^ A_xor[l - 1] ? "NO" : "YES") << endl;
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