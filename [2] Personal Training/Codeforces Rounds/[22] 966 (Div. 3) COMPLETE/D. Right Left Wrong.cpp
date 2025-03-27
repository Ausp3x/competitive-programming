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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;
    string s;
    cin >> s;

    vector<lng> A_prf(n + 1);
    for (int i = 1; i <= n; i++)
        A_prf[i] = A_prf[i - 1] + A[i - 1];
    
    int l = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            break;

        l++;
    }

    int r = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'R')
            break;

        r--;
    }

    lng ans = 0;
    while (l < r) {
        ans += A_prf[r] - A_prf[l - 1];

        l++;   
        while (l <= n && s[l - 1] == 'R')
            l++;

        r--;
        while (r >= 1 && s[r - 1] == 'L')
            r--;
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