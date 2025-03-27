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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ops(n);
    for (int i = 0; i < n; i++)
        cin >> ops[i].first;
    for (int i = 0; i < n; i++)
        cin >> ops[i].second;

    int one_one = 0, neg_neg = 0;
    vector<int> ttls(2);
    for (int i = 0; i < n; i++) {
        if (ops[i].first == 1 && ops[i].second == 1) {
            one_one++;
            continue;
        }

        if (ops[i].first == -1 && ops[i].second == -1) {
            neg_neg++;
            continue;
        }

        if (ops[i].first >= ops[i].second)
            ttls[0] += ops[i].first;
        else
            ttls[1] += ops[i].second;
    }

    for (int i = 0; i < one_one; i++)
        if (ttls[0] <= ttls[1])
            ttls[0]++;
        else
            ttls[1]++;

    for (int i = 0; i < neg_neg; i++)
        if (ttls[0] > ttls[1])
            ttls[0]--;
        else
            ttls[1]--;
    
    cout << min(ttls[0], ttls[1]) << endl;

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