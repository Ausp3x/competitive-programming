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
    int n;
    cin >> n;
    int G = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        G = gcd(G, a);
    }

    int g = 0;
    lng ans = 0;
    vector<bool> vst(n);
    for (int i = 0; i < n; i++) {
        int mn = INF32, idx = -1;
        for (int j = 0; j < n; j++) {
            if (vst[j])
                continue;

            if (gcd(g, A[j]) < mn) {
                mn = gcd(g, A[j]);
                idx = j;
            }
        }

        g = mn;
        ans += mn;
        vst[idx] = true;

        if (g == G) {
            ans += 1ll * (n - i - 1) * G;
            break;
        }
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