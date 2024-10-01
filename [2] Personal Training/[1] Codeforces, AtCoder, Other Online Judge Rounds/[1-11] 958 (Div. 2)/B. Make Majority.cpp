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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string s_pruned = "X";
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && s[i - 1] != '0')
            s_pruned += s[i];
        else if (s[i] == '1')
            s_pruned += s[i];
    }

    // cout << s_pruned << endl;

    int zero = 0, one = 0;
    for (int i = 1; i < s_pruned.size(); i++)
        if (s_pruned[i] == '0')
            zero++;
        else    
            one++;

    cout << (one > zero ? "Yes" : "No") << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}