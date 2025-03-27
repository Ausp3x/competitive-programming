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
    string s;
    cin >> s;
    int n = s.size();
    
    array<int, 3> cnts = {0, 0, 0};
    for (int i = 0; i < n; i++)
        cnts[s[i] - 'A']++;

    if (cnts[0] == n || cnts[1] == n || cnts[2] == n) {
        cout << 0 << endl;
        return;
    }

    if (cnts[0] == 0 || cnts[1] == 0 || cnts[2] == 0) {
        int ans = INF32, cur = 0;
        for (int i = 0; i < cnts[s[0] - 'A']; i++)
            cur += (s[i] != s[0]);
        ans = min(ans, cur);
        for (int i = 1; i < n; i++) {
            cur -= (s[i - 1] != s[0]);
            cur += (s[(i + cnts[s[0] - 'A'] - 1) % n] != s[0]);
            ans = min(ans, cur);
        }

        cout << ans << endl;
        return;
    }

    vector<int> A(n), Ab(n);
    for (int i = 0; i < cnts[0]; i++) {
        A[0] += (s[i] != 'A');
        Ab[0] += (s[i] == 'B');
    }
    for (int i = 1; i < n; i++) {
        A[i] = A[i - 1];
        A[i] -= (s[i - 1] != 'A');
        A[i] += (s[(i + cnts[0] - 1) % n] != 'A');
        Ab[i] = Ab[i - 1];
        Ab[i] -= (s[i - 1] == 'B');
        Ab[i] += (s[(i + cnts[0] - 1) % n] == 'B');
    }

    vector<int> B(n), Ba(n);
    for (int i = 0; i < cnts[1]; i++) {
        B[0] += (s[i] != 'B');
        Ba[0] += (s[i] == 'A');
    }
    for (int i = 1; i < n; i++) {
        B[i] = B[i - 1];
        B[i] -= (s[i - 1] != 'B');
        B[i] += (s[(i + cnts[1] - 1) % n] != 'B');
        Ba[i] = Ba[i - 1];
        Ba[i] -= (s[i - 1] == 'A');
        Ba[i] += (s[(i + cnts[1] - 1) % n] == 'A');
    }
    
    int ans = INF32;
    for (int i = 0; i < n; i++) {
        ans = min(ans, A[i] + B[(i + cnts[0]) % n] - min(Ab[i], Ba[(i + cnts[0]) % n]));
        ans = min(ans, A[i] + B[((i - cnts[1]) % n + n) % n] - min(Ab[i], Ba[((i - cnts[1]) % n + n) % n]));
    }

    cout << ans << endl;

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