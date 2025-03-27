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
    string s;
    cin >> s;
    string r;
    cin >> r;

    array<int, 2> cnts = {0, 0};
    for (int i = 0; i < n; i++)
        cnts[s[i] - '0']++;

    for (int i = 0; i < n - 1; i++) {
        if (cnts[0] == 0 || cnts[1] == 0) {
            cout << "NO" << endl;
            return;
        }

        if (r[i] == '0') 
            cnts[1]--;
        else if (r[i] == '1')
            cnts[0]--;
    }

    cout << "YES" << endl;
    
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