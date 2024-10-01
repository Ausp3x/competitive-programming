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
    vector<int> A(n);
    vector<int> cnts(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cnts[A[i]]++;
    }

    for (int i = 1; i <= n; i++)
        cnts[i] += cnts[i - 1];

    // for (int x : cnts)
    //     cout << x << ' ';
    // cout << endl;

    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) {
        int l = -1, r = i;
        while (r - l > 1) {
            int md = (l + r) / 2;
            
            // cout << md << endl;

            int cnt = cnts[md];
            for (int j = 1; j * i <= n; j++)
                cnt += cnts[min(j * i + md, n)] - cnts[j * i - 1];

            if (cnt >= n / 2 + 1) 
                r = md;
            else
                l = md;
        }
        res[i] = r;
    }

    while (q--) {
        int x;
        cin >> x;

        cout << res[x] << ' ';
    }
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