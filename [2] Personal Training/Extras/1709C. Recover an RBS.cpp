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
    string s;
    cin >> s;

    int n = s.size(), cnt = 0, remaining_close = n / 2 - count(s.begin(), s.end(), ')');
    int first_close = INF32, last_open = -INF32;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') {
            cnt++;
            
            if (cnt < 0) {
                cout << "NO" << endl;
                return;
            }

            continue;
        } else if (s[i] == '(') {
            cnt--;
            
            if (cnt < 0) {
                cout << "NO" << endl;
                return;
            }

            continue;
        }

        if (remaining_close > 0) {
            s[i] = ')';
            cnt++;
            remaining_close--;
            first_close = i;
        } else {
            s[i] = '(';
            cnt--;
            last_open = max(last_open, i);
        }

        if (cnt < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    // cout << s << endl;

    if (cnt != 0) {
        cout << "NO" << endl;
        return;
    }

    if (first_close == INF32 || last_open == -INF32) {
        cout << "YES" << endl;
        return;
    }

    swap(s[first_close], s[last_open]);

    // cout << s << endl;

    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') { 
            cnt++;
        } else if (s[i] == '(') {
            cnt--;
        }

        if (cnt < 0) {
            cout << "YES" << endl;
            return;
        }
    }

    if (cnt != 0) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

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