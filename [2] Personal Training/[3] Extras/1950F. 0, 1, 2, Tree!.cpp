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
    array<int, 3> A;
    cin >> A[0] >> A[1] >> A[2];
    
    swap(A[0], A[2]);

    if (A[2] + 1 != A[0]) {
        cout << -1 << endl;
        return;
    }

    int ans = -1;
    int cur = 1;
    while (true) {
        if (cur == 0)
            break;
        ans++;

        int nxt = 0;
        for (int i = 2; i >= 0; i--) {
            int d = min(A[i], cur);
            nxt += d * i;
            A[i] -= d;
            cur -= d;
        }

        cur = nxt;
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