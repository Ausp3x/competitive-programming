// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define DEBUG

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    map<char, int> ltr_vals = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 10}, {'Q', 10}, {'K', 10}};
    vector<char> val_ltrs = {'X', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T'};
    
    int sum = 0;
    vector<int> joker_idxs;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            joker_idxs.push_back(i);
        } else {
            sum += ltr_vals[s[i]];
        }
    }

    int len = joker_idxs.size();
    if (sum + len > m) {
        cout << "NO\n";
        return;
    }
    
    if (sum + 10 * len < m) {
        cout << "NO\n";
        return;
    }

    m -= sum + len;
    for (int &x : joker_idxs) {
        int cur = min(m, 9);
        s[x] = val_ltrs[cur + 1];
        m -= cur;
    }

    cout << "YES\n" << s << '\n';

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}