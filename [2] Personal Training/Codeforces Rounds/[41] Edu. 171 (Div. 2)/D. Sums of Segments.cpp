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
    int n;
    cin >> n;
    vector<lng> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        A[i] += A[i - 1];
    }

    // for (lng a : A)
    //     cout << a << ' ';
    // cout << endl;

    vector<lng> A_prf(n + 1);
    for (int i = 1; i <= n; i++)
        A_prf[i] = A_prf[i - 1] + A[i];
    
    // for (lng a_prf : A_prf)
    //     cout << a_prf << ' ';
    // cout << endl;

    vector<lng> B(n + 1);
    for (int i = 1; i <= n; i++) {
        B[i] = A_prf[n] - A_prf[i - 1] - (n - i + 1) * A[i - 1];
        B[i] += B[i - 1];
    }

    // for (lng b : B)
    //     cout << b << ' ';
    // cout << endl;

    vector<lng> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        L[i] = R[i - 1] + 1;
        R[i] = L[i] + n - i;
    }

    // for (lng l : L)
    //     cout << l << ' ';
    // cout << endl;
    // for (lng r : R)
    //     cout << r << ' ';
    // cout << endl;

    int q;
    cin >> q;
    while (q--) {
        lng l, r;
        cin >> l >> r;

        // a_l
        int a_l = 0, a_r = n + 1;
        while (a_r - a_l > 1) {
            int a_md = (a_l + a_r) / 2;

            if (L[a_md] <= l)
                a_l = a_md;
            else
                a_r = a_md;
        }

        // b_r
        int b_l = 0, b_r = n + 1;
        while (b_r - b_l > 1) {
            int b_md = (b_l + b_r) / 2;

            if (R[b_md] >= r)
                b_r = b_md;
            else
                b_l = b_md;
        }

        // cout << a_l << ' ' << b_r << ' ';

        lng ans = B[b_r] - B[a_l - 1];

        // cout << ans << endl;
        
        lng ll = L[a_l] - 1ll * (n - 1) * n / 2 + 1ll * (n - a_l) * (n - a_l + 1) / 2;
        l -= 1ll * (n - 1) * n / 2 - 1ll * (n - a_l) * (n - a_l + 1) / 2;

        // cout << ll << ' ' << l << endl;

        ans -= A_prf[l - 1] - A_prf[a_l - 1] - (l - 1 - a_l + 1) * A[a_l - 1]; 
        ans += A_prf[ll - 1] - A_prf[a_l - 1] - (ll - 1 - a_l + 1) * A[a_l - 1];

        r -= 1ll * (n - 1) * n / 2 - 1ll * (n - b_r) * (n - b_r + 1) / 2;
        lng rr = R[b_r] - 1ll * (n - 1) * n / 2 + 1ll * (n - b_r) * (n - b_r + 1) / 2;

        // cout << r << ' ' << rr << endl;

        ans += A_prf[r] - A_prf[b_r - 1] - (r - b_r + 1) * A[b_r - 1];
        ans -= A_prf[rr] - A_prf[b_r - 1] - (rr - b_r + 1) * A[b_r - 1];

        cout << ans << endl;
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