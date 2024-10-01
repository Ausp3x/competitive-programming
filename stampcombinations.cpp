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
    int n, m;
    cin >> n >> m;
    int A_sum = 0;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
        A_sum += a;
    }

    vector<int> L(n + 1);
    for (int i = 1; i <= n; i++)
        L[i] = L[i - 1] + A[i - 1];

    reverse(A.begin(), A.end());

    // for (int x : L)
    //     cout << x << ' ';
    // cout << endl;

    vector<int> R(n + 1);
    for (int i = 1; i <= n; i++)
        R[i] = R[i - 1] + A[i - 1];

    reverse(A.begin(), A.end());

    // for (int x : R)
    //     cout << x << ' ';
    // cout << endl;

    while (m--) {
        int q;
        cin >> q;

        int j = 0;
        for (int i = n; i >= 0; i--) {
            while (i + j + 1 <= n && L[i] + R[j + 1] <= q)
                j++;

            // cout << i << ' ' << j << ' ' << L[i] + R[j] << endl;

            if (L[i] + R[j] == q) {
                cout << "Yes" << endl;
                goto exit;
            }
        }

    cout << "No" << endl;

exit:
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