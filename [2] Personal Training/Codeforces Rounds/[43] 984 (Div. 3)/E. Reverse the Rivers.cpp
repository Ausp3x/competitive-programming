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

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<lng>> A(n + 1, vector<lng>(k + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> A[i][j];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
            A[i][j] |= A[i - 1][j];

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= k; j++) 
    //         cout << A[i][j] << ' ';
    //     cout << endl;
    // }

    vector<int> L(k + 1, 1), R(k + 1, n);
    while (q--) {
        bool is_good = true;
        int l = 1, r = n;
        
        int m;
        cin >> m;
        vector<int> edited_regions;
        while (m--) {
            int k;
            char o;
            int c;
            cin >> k >> o >> c;

            edited_regions.pb(k);

            if (o == '<')  {
                if (A[L[k]][k] >= c) {
                    is_good = false;
                    continue;
                }

                for (int i = 1'048'576; i >= 1; i /= 2) {
                    if (R[k] - i < L[k])
                        continue;

                    if (A[R[k] - i][k] >= c)
                        R[k] -= i;
                }
                if (A[R[k]][k] >= c)
                    R[k]--;
            
                l = max(l, L[k]);
                r = min(r, R[k]);
            } else if (o == '>') {
                if (A[R[k]][k] <= c) {
                    is_good = false;
                    continue;
                }

                for (int i = 1'048'576; i >= 1; i /= 2) {
                    if (L[k] + i > R[k])
                        continue;

                    if (A[L[k] + i][k] <= c)
                        L[k] += i;
                }
                if (A[L[k]][k] <= c)
                    L[k]++;

                l = max(l, L[k]);
                r = min(r, R[k]);
            } else {
                cout << "DAFUQ?" << endl;
                exit(0);
            }
        }

        cout << (is_good && (l <= r) ? l : -1) << endl;

        for (int x : edited_regions) {
            L[x] = 1;
            R[x] = n;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}