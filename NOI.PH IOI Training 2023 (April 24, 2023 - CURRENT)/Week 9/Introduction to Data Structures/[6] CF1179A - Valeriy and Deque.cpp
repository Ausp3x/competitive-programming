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
    int a_max = 0;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        a_max = max(a_max, a);
        dq.push_back(a);
    }

    vector<pair<int, int>> init;
    while (dq[0] != a_max) {
        int a = dq[0], b = dq[1];
        
        dq.pop_front();
        dq.pop_front();

        init.push_back({a, b});

        dq.push_front(max(a, b));
        dq.push_back(min(a, b));
    }

    vector<pair<int, int>> cycle;
    for (int i = 0; i < n - 1; i++) {
        int a = dq[0], b = dq[1];

        dq.pop_front();
        dq.pop_front();

        cycle.push_back({a, b});

        dq.push_front(max(a, b));
        dq.push_back(min(a, b));
    }

    while (q--) {
        lng m;
        cin >> m;

        m--;

        if (m < int(init.size())) {
            cout << init[m].first << ' ' << init[m].second << endl;
            
            continue;
        }

        m -= init.size();

        cout << cycle[m % (n - 1)].first << ' ' << cycle[m % (n - 1)].second << endl;
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