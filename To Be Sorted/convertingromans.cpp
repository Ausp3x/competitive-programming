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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

map<char, int> roman_to_int = {
    {'I', 1}, 
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    if (s.empty()) {
        cout << 0 << endl;
        return;
    }

    char max_digit = s[n - 1];
    vector<int> max_digit_idxs(n);
    max_digit_idxs[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
        if (roman_to_int[s[i]] > roman_to_int[max_digit]) {
            max_digit = s[i];
            max_digit_idxs[i] = i;
        } else if (roman_to_int[s[i]] == roman_to_int[max_digit]) {
            max_digit_idxs[i] = i;
        } else {
            max_digit_idxs[i] = i + 1;
        }

    lng ans = 0;
    for (int i = 0; i < n; i++) 
        if (max_digit_idxs[i] == i) 
            ans += roman_to_int[s[i]];
        else 
            ans -= roman_to_int[s[i]];

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