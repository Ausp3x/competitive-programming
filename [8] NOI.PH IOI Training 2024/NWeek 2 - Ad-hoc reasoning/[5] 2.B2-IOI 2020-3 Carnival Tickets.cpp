// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "tickets.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long         lng;
typedef pair<int, int>    pi;
typedef vector<int>       vi;
typedef pair<lng, lng>    pl;
typedef vector<lng>       vl;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng find_maximum(int k, vector<vi> x) {
    int n = x.size(), m = x[0].size();
    // val, idx
    vector<vector<pi>> sorted_x(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sorted_x[i].pb({x[i][j], i * m + j});

    for (int i = 0; i < n; i++)
        sort(sorted_x[i].begin(), sorted_x[i].end());

    lng S = 0;
    // val, idx
    vector<priority_queue<pi>> minus(n), unused(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            S -= sorted_x[i][j].fi;
            minus[i].push(sorted_x[i][j]);
        }

        for (int j = k; j < m; j++)
            unused[i].push(sorted_x[i][j]);
    }

    // sum, col
    priority_queue<pi> max_change;
    for (int i = 0; i < n; i++)
        if (unused[i].size() > 0)
            max_change.push({unused[i].top().fi + minus[i].top().fi, i});
        else
            max_change.push({2 * minus[i].top().fi, i});

    int cnt = 0;
    vector<tuple<int, deque<int>, deque<int>>> plus(n);
    while (cnt < k * n / 2) {
        auto [sum, col] = max_change.top();
        max_change.pop();

        S += sum;

        if (unused[col].size() > 0) {
            pi unused_cur = unused[col].top();
            pi minus_cur = minus[col].top();
            unused[col].pop();
            minus[col].pop();

            unused[col].push(minus_cur);
            get<0>(plus[col])++;
            get<1>(plus[col]).pb(unused_cur.fi);
            get<2>(plus[col]).pb(unused_cur.se);

            if (unused[col].size() > 0 && minus[col].size() > 0)
                max_change.push({unused[col].top().fi + minus[col].top().fi, col});
        } else {
            pi minus_cur = minus[col].top();
            minus[col].pop();

            get<0>(plus[col])++;
            get<1>(plus[col]).pb(minus_cur.fi);
            get<2>(plus[col]).pb(minus_cur.se);

            if (minus[col].size() > 0)
                max_change.push({2 * minus[col].top().fi, col});
        }

        cnt++;
    }

    for (int i = 0; i < n; i++)
        while (!minus[i].empty()) {
            get<1>(plus[i]).pb(minus[i].top().fi);
            get<2>(plus[i]).pb(minus[i].top().se);
            minus[i].pop();
        }

#ifdef DEBUG
    cout << S << endl;
    for (int i = 0; i < n; i++) {
        cout << get<0>(plus[i]) << ": ";
        for (int x : get<1>(plus[i]))
            cout << x << ' ';
        cout << endl;
    }
#endif

    vector<vi> s(n, vi(m, -1));
    for (int i = 0; i < k; i++) {
        vector<pi> plus_idxs;
        for (int j = 0; j < n; j++)
            plus_idxs.push_back({get<0>(plus[j]), j});

        sort(plus_idxs.begin(), plus_idxs.end(), greater<pi>());

#ifdef DEBUG
        cout << S << endl;
        for (int j = 0; j < n; j++) {
            cout << get<0>(plus[j]) << ": ";
            for (int x : get<1>(plus[j]))
                cout << x << ' ';
            cout << endl;
        }
#endif

        for (int j = 0; j < n / 2; j++) {
            int val = get<1>(plus[plus_idxs[j].se]).front();
            int idx = get<2>(plus[plus_idxs[j].se]).front();
            get<1>(plus[plus_idxs[j].se]).pop_front();
            get<2>(plus[plus_idxs[j].se]).pop_front();

            get<0>(plus[plus_idxs[j].se])--;
            s[idx / m][idx % m] = i;
        }

        for (int j = n / 2; j < n; j++) {
            int idx = get<2>(plus[plus_idxs[j].se]).back();
            get<1>(plus[plus_idxs[j].se]).pop_back();
            get<2>(plus[plus_idxs[j].se]).pop_back();

            s[idx / m][idx % m] = i;
        }
    }

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << s[i][j] << ' ';
        cout << endl;
    }
#endif

#ifndef DEBUG
    allocate_tickets(s);
#endif
    return S;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vi> x(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> x[i][j];

        cout << find_maximum(k, x) << endl;
    }

    return 0;
}
#endif