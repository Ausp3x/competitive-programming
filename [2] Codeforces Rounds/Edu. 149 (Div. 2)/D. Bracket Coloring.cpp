// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define ONLINE_JUDGE
// #define DEBUG

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    int l_cnt = 0, r_cnt = 0;
    for (char &x : s) {
        if (x == '(') {
            l_cnt++;
        } else if (x == ')') {
            r_cnt++;
        }
    }

    if (l_cnt != r_cnt) {
        cout << -1 << endl;
        return;
    }

    string s_rev;
    for (int i = n - 1; i >= 0; i--) {
        s_rev += s[i];
    }

    bool chk = true;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (s_rev[i] == '(') {
            stk.push(i);
        } else {
            if (stk.empty()) {
                chk = false;
            } else {
                stk.pop();
            }
        }
    }
    chk = stk.empty();

    if (chk) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << ' ';
        }
        cout << endl;
        return;
    }

    vector<int> ans(n, 1);
    stk = stack<int>();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            if (stk.empty()) {
                ans[i] = 2;
            } else {
                ans[stk.top()] = 1;
                ans[i] = 1;
                stk.pop();
            }
        }
    }
    while (!stk.empty()) {
        ans[stk.top()] = 2;
        stk.pop();
    }


    set<int> dis_colors;
    for (int &x : ans) {
        dis_colors.insert(x);
    }

    int k = dis_colors.size();
    cout << k << endl;
    for (int &x : ans) {
        cout << min(x, k) << ' ';
    }
    cout << endl;

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
    cin >> t;
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