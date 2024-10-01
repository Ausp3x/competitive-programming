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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    lng m;
    cin >> n >> m;
    lng max_MEX = -1;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        ordered_set<int> A;
        for (int j = 0; j < l; j++) {
            int a;
            cin >> a;
            A.insert(a);
        }

        // cout << "list " << i << ": ";
        // for (int a : A)
        //     cout << a << ' ';
        // cout << endl;

        for (int j = 0; j <= l; j++) 
            if (A.find(j) == A.end()) {
                A.insert(j);
                break;
            }

        // cout << "list* " << i << ": ";
        // for (int a : A)
        //     cout << a << ' ';
        // cout << endl;

        for (int j = 0; j <= l + 1; j++) 
            if (A.find(j) == A.end()) {
                // cout << i << ' ' << j << endl;

                max_MEX = max<lng>(max_MEX, j);
                break;
            }
    }

    // cout << max_MEX << ' ';
    cout << max_MEX + max_MEX * min(max_MEX, m) + m * (m + 1) / 2 - min(max_MEX, m) * (min(max_MEX, m) + 1) / 2 << endl;
    // cout << endl;
     
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