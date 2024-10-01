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
    int n, k;
    cin >> n >> k;
    vector<vector<string>> S(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        while (t--) {
            string topic;
            cin >> topic;

            S[i].push_back(topic);
        }
    }
    
    int limit = k / 2;
    int ans = 0;
    for (int msk = 0; msk < (1 << n); msk++) {
        vector<int> Q;
        for (int i = 0; i < n; i++)
            if (msk & (1 << i))
                Q.push_back(i);

        if (Q.size() != k)
            continue;

        bool is_valid = true;
        unordered_map<string, int> cnts;
        for (int i : Q) 
            for (auto s : S[i]) {
                    cnts[s]++;
                    if (cnts[s] > limit) {
                        is_valid = false;
                        goto exit;
                    }
                }

    exit:
        ans += is_valid;
    }

    cout << ans << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}