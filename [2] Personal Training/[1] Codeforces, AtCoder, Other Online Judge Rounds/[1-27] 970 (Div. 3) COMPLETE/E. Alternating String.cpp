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
    string s;
    cin >> s;

    if (n % 2 == 0) {
        vector<int> evn_cnts(26), odd_cnts(26);
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                evn_cnts[s[i] - 'a']++;
            else
                odd_cnts[s[i] - 'a']++;
    
        int evn_max = 0, odd_max = 0;
        for (int i = 0; i < 26; i++) {
            evn_max = max(evn_max, evn_cnts[i]);
            odd_max = max(odd_max, odd_cnts[i]);
        }

        cout << n - evn_max - odd_max << endl;
        return;
    }

    vector<int> evn_cnts(26), odd_cnts(26);
    for (int i = 1; i < n; i++)
        if ((i - 1) % 2 == 0)
            evn_cnts[s[i] - 'a']++;
        else
            odd_cnts[s[i] - 'a']++;

    int ans = INF32;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if ((i - 1) % 2 == 0) {
                evn_cnts[s[i - 1] - 'a']++;
                evn_cnts[s[i] - 'a']--;
            } else {
                odd_cnts[s[i - 1] - 'a']++;
                odd_cnts[s[i] - 'a']--;
            }
        }

        int evn_max = 0, odd_max = 0;
        for (int i = 0; i < 26; i++) {
            evn_max = max(evn_max, evn_cnts[i]);
            odd_max = max(odd_max, odd_cnts[i]);
        }

        ans = min(ans, n - evn_max - odd_max);
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