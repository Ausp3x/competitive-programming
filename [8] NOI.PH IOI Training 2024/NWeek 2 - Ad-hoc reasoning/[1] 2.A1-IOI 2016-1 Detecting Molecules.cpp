// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

vector<int> find_subset(int l, int u, vector<int> w) {
    int n = w.size();

    if (u <= 10000 && n <= 10000) {
        vector<int> dp(u + 1, -1);
        for (int i = 0; i < n; i++)
            for (int j = u; j >= 0; j--) {
                if (j - w[i] < 0)
                    continue;

                if (j - w[i] == 0) {
                    if (dp[j] == -1)
                        dp[j] = i;
                    continue;
                }

                if (dp[j] != -1 || dp[j - w[i]] == -1)
                    continue;
                
                dp[j] = i;
            }

        // for (int i = 0; i <= u; i++)
        //     cout << dp[i] << ' ';
        // cout << endl;

        vector<int> ans;
        for (int i = l; i <= u; i++) {
            if (dp[i] == -1)
                continue;

            int ii = i;
            while (ii > 0) {
                ans.push_back(dp[ii]);
                ii -= w[dp[ii]];
            }

            break;
        }

        return ans;
    }

    vector<pair<int, int>> w_idxs;
    for (int i = 0; i < n; i++)
        w_idxs.push_back({w[i], i});
    
    sort(w_idxs.begin(), w_idxs.end());

    int lft = 0, rht = n;
    while (lft <= rht) {
        int md = (lft + rht) / 2;

        lng sum = 0;
        for (int i = 0; i < md; i++)
            sum += w_idxs[i].first;

        if (sum > u) {
            rht = md - 1;
            continue;
        }

        int j = n;
        while (sum < l && n - j < md && j > md) {
            j--;
            sum -= w_idxs[n - j - 1].first;
            sum += w_idxs[j].first;
        }

        if (sum < l) 
            lft = md + 1;
        else {
            vector<int> ans;
            for (int i = n - j; i < md; i++)
                ans.push_back(w_idxs[i].second);
            for (int i = j; i < n; i++)
                ans.push_back(w_idxs[i].second);

            return ans;
        }
    }

    return {};
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int l, u, n;
        cin >> l >> u >> n;
        vector<int> w(n);
        for (int &x : w)
            cin >> x;
        
        vector<int> ans = find_subset(l, u, w);

        cout << ans.size() << endl;
        for (int x : ans)
            cout << x << ' ';
        cout << endl;
    }

    return 0;
}
//*/