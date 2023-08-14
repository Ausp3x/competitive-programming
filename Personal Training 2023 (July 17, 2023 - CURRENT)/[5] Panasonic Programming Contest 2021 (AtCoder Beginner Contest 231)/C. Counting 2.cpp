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
    int n, q;
    cin >> n >> q;
    map<int, int> h_cnts;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        h_cnts[h]++;
    }

    for (auto itr = ++h_cnts.rbegin(); itr != h_cnts.rend(); itr++) {
        itr->second += prev(itr)->second;
    }

    while (q--) {
        int x;
        cin >> x;
        
        cout << h_cnts.lower_bound(x)->second << endl;
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