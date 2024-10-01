// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    map<string, int> candidate_cnts;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        candidate_cnts[s]++;
    }

    int max_cnt = 0;
    string ans;
    for (auto &[k, v] : candidate_cnts) {
        if (v > max_cnt) {
            max_cnt = v;
            ans = k;
        }
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