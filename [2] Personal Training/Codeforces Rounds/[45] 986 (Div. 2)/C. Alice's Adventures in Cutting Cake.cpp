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
    int n, m, v;
    cin >> n >> m >> v;
    lng A_sum = 0;
    vector<lng> A(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A_sum += A[i];
    }

    // for (lng a : A)
    //     cout << a << ' ';
    // cout << endl;

    vector<lng> A_prf(n + 2, 0);
    for (int i = 1; i <= n; i++)
        A_prf[i] = A_prf[i - 1] + A[i];

    // for (lng x : A_prf)
    //     cout << x << ' ';
    // cout << endl;

    vector<lng> A_suf(n + 2, 0);
    for (int i = n; i >= 1; i--)
        A_suf[i] = A_suf[i + 1] + A[i];

    // for (lng x : A_suf)
    //     cout << x << ' ';
    // cout << endl;

    vector<int> L(m + 2, 0);
    for (int i = 1; i <= m + 1; i++) {
        L[i] = L[i - 1];
        while (L[i] + 1 <= n && A_prf[L[i]] - A_prf[L[i - 1]] < v)
            L[i]++;
    }

    // for (int l : L)
    //     cout << l << ' ';
    // cout << endl;

    for (int i = m + 1; i >= 1; i--)
        if (A_prf[L[i]] - A_prf[L[i - 1]] < v)
            L[i] = -1;
        else
            break;

    vector<int> R(m + 2, 0);
    R[0] = n + 1;
    for (int i = 1; i <= m + 1; i++) {
        R[i] = R[i - 1];
        while (R[i] - 1 >= 1 && A_suf[R[i]] - A_suf[R[i - 1]] < v)
            R[i]--;
    }

    // for (int r : R)
    //     cout << r << ' ';
    // cout << endl;

    for (int i = m + 1; i >= 1; i--)
        if (A_suf[R[i]] - A_suf[R[i - 1]] < v)
            R[i] = -1;
        else
            break; 

    // for (int l : L)
    //     cout << l << ' ';
    // cout << endl;

    // for (int r : R)
    //     cout << r << ' ';
    // cout << endl;

    lng ans = -1;
    for (int i = 0; i <= m; i++) { 
        if (L[i] == -1 || R[m - i] == -1)
            continue;
        
        if (L[i] >= R[m - i])
            continue;

        ans = max(ans, A_sum - A_prf[L[i]] - A_suf[R[m - i]]);
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