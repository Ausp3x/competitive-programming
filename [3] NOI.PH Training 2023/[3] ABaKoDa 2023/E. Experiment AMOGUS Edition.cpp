// 人外有人，天外有天
// author: Ausp3x

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
    int k;
    cin >> k; // k is always 18
    
    int n = 48620;
    cout << n << endl;
    
    int cnt = 1;
    vector<vector<int>> ans(k);
    for (int i = 0; i < (1 << k); i++) {
        if (__builtin_popcount(i) != k / 2) {
            continue;
        }

        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                ans[j].push_back(cnt);
            }
        }
        
        cnt++;
    }

    for (auto x : ans) {
        cout << x.size() << endl;
        for (int y : x) {
            cout << y << ' ';
        }
        cout << endl;

        string res;
        cin >> res;
        if (res != "SILENCE...") {
            cin >> res >> res;
            break;
        }
    }

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