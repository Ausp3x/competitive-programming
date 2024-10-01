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
    map<int, vector<int>> a_idxs;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        a_idxs[a].pb(i);
    }

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;

        if (a_idxs.size() > 26) {
            cout << "NO" << endl;
            continue;
        }

        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }

        bool chk = true;
        vector<bool> is_used(26);
        for (auto &[a, idxs] : a_idxs) {
            char c = s[idxs[0]];
            for (int i = 1; i < idxs.size(); i++)
                if (s[idxs[i]] != c) {
                    chk = false;
                    break;
                }

            if (!chk)
                break;

            if (is_used[c - 'a']) {
                chk = false;
                break;
            }
            is_used[c - 'a'] = true;
        }

        cout << (chk ? "YES" : "NO") << endl;
    }


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