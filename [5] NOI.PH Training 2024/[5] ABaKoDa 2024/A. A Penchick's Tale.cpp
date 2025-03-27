// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
    vector<lng> V(3);
    cin >> V[0] >> V[1] >> V[2];
    string s;
    cin >> s;

    vector<int> cnts(26);
    for (char c : s)
        cnts[c - 'a']++;
    
    int n = s.size();
    int a = min({cnts[16], cnts[20], cnts[0], cnts[10]});
    int b = cnts[2];
    int c = min({cnts[18], cnts[22]});
    int d = min({cnts[7], cnts[8], cnts[17], cnts[15]});
    lng max_sum = 0;
    vector<int> ans;
    for (int k = 0; k <= min(a, b); k++) {
        int i = min(a - k, c);
        int j = min(b - k, d);

        lng sum = V[0] * i + V[1] * j + V[2] * k;
        if (sum > max_sum) {
            max_sum = sum;
            ans = {i, j, k};
        }
    }

    if (max_sum == 0) {
        cout << "penchickdead" << endl;
        return;
    }

    vector<string> S = {"squawk", "chirp", "quack"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < ans[i]; j++)
            cout << S[i] << ' ';
    }
    cout << endl;
    
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