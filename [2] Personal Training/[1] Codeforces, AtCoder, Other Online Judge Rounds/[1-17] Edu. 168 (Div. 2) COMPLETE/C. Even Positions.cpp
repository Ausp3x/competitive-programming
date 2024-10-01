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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            if (cur < -1) {
                s[i] = '(';
            } else if (cur == -1) {
                if (i > 0) {
                    if (s[i - 1] == '(')
                        s[i] = ')';
                    else
                        s[i] = '(';
                } else {
                    s[i] = '(';
                }
            } else {
                cout << "No!" << endl;
                return;
            }
        }

        if (s[i] == '(')
            cur++;
        else
            cur--;
    }

    lng ans = 0;
    stack<int> l_idxs;
    for (int i = 0; i < n; i++) 
        if (s[i] == '(')
            l_idxs.push(i);
        else {
            ans += i - l_idxs.top();
            l_idxs.pop();
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