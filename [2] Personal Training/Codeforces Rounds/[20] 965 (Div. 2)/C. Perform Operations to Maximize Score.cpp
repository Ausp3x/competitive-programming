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

pair<int, int> maxMedianBinSearch(int k, int add_cnt, const vector<pair<lng, bool>> &arr) {
    int n = arr.size();

    int i_md = (n - 1) / 2;
    lng l = 0, r = 2000000001;
    lng rem_k = k;
    while (r - l > 1) {
        lng md = (l + r) / 2;
    
        int cur_cnt = add_cnt;
        vector<int> to_be_added;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i].se == 1) {
                if (arr[i].fi < md)
                    to_be_added.pb(arr[i].fi);

                continue;
            }
            
            if (arr[i].fi >= md)
                cur_cnt++;
        }

        if (cur_cnt < n - i_md) {
            r = md;
            continue;
        }

        int req = (n - i_md) - (cur_cnt - to_be_added.size());
        lng cur_k = 0;
        for (int i = 0; i < req; i++)
            cur_k += md - to_be_added[i];

        if (cur_k <= k) {
            l = md;
            rem_k = k - cur_k;
        } else 
            r = md;
    }

    return {l, rem_k};
}

void solve(int t) {
    int n, k;
    cin >> n >> k;
    vector<pair<lng, bool>> AB(n);
    for (auto &[a, b] : AB) 
        cin >> a;
    int add_cnt = 0;
    for (auto &[a, b] : AB) {
        cin >> b;
        add_cnt += b;
    }

    sort(AB.begin(), AB.end());

    lng ans = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (AB[i].se == 1)
            continue;

        int cur_add_cnt = 0;
        vector<pair<lng, bool>> cur_AB;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;

            cur_add_cnt += AB[j].se;
            cur_AB.pb(AB[j]);
        }

        auto [median, rem_k] = maxMedianBinSearch(k, cur_add_cnt, cur_AB);
        // cout << AB[i].fi + median << endl;
        ans = max(ans, AB[i].fi + median);
        break;
    }

    for (int i = n - 1; i >= n / 2; i--) {
        if (AB[i].se == 0)
            continue;
        
        int cur_add_cnt = 0;
        vector<pair<lng, bool>> cur_AB;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;

            cur_add_cnt += AB[j].se;
            cur_AB.pb(AB[j]);
        }

        // for (auto [x, y] : cur_AB)
        //     cout << x << ' ';
        // cout << endl;

        ans = max(ans, AB[i].fi + k + cur_AB[n / 2 - 1].fi);
        // cout << AB[n / 2 - 1].fi + AB[i].fi + k << ", ";

        auto [median, rem_k] = maxMedianBinSearch(k, cur_add_cnt, cur_AB);
        // cout << AB[i].fi << ' ' << median << ' ' << rem_k << ' ' << AB[i].fi + median + rem_k << endl;
        ans = max(ans, AB[i].fi + median + rem_k);
        break;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        if (AB[i].se == 0)
            continue;

        int cur_add_cnt = 0;
        vector<pair<lng, bool>> cur_AB;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;

            cur_add_cnt += AB[j].se;
            cur_AB.pb(AB[j]);
        }

        // for (auto [x, y] : cur_AB)
        //     cout << x << ' ';
        // cout << endl;

        ans = max(ans, AB[i].fi + k + cur_AB[n / 2 - 1].fi);
        // cout << AB[n / 2].fi + AB[i].fi + k << ", "; 

        auto [median, rem_k] = maxMedianBinSearch(k, cur_add_cnt, cur_AB);
        // cout << AB[i].fi << ' ' << median << ' ' << rem_k << ' ' << AB[i].fi + median + rem_k << endl;
        ans = max(ans, AB[i].fi + median + rem_k);
        break;
    }

    cout << ans << endl;
    // cout << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}