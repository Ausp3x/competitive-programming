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

int N = 50;
vector<lng> X(N + 1), P(N + 1);

void solve() {
    lng n, x;
    cin >> n >> x;
    
    if (n == 0) {
        cout << 1 << endl;
        return;
    }

    lng ans = 0, y = 0;
    for (int i = n; i >= 0; i--) {
        if (y >= x)
            break;
        
        if (y + X[i] <= x) {
            ans += P[i];
            y += X[i];
        } else {
            y++;
            continue;
        }

        if (y + 1 <= x) {
            ans++;
            y++;
        } else {
            break;
        }

        if (y + X[i] <= x) {
            ans += P[i];
            y += X[i];
            break;
        } else {
            y++;
            continue;
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    X[0] = 1;
    P[0] = 1;
    for (int i = 1; i <= N; i++) {
        X[i] = 2 * X[i - 1] + 3;
        P[i] = 2 * P[i - 1] + 1;
    }

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}