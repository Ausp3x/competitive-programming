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
    int n;
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> P[i];
    string s;
    cin >> s;
    s = "X" + s;

    int clr = 0;
    vector<int> C(n + 1, -1);
    map<int, int> cnts;
    for (int i = 1; i <= n; i++) {
        if (C[i] != -1)
            continue;

        int j = i;
        do {
            C[j] = clr;
            cnts[clr] += s[j] == '0';
            j = P[j];
        } while (C[j] == -1);

        clr++;
    }

    for (int i = 1; i <= n; i++) 
        cout << cnts[C[i]] << ' ';
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