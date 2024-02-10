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
    vector<pair<int, int>> adjl(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> adjl[i].first >> adjl[i].second;
    }

    vector<bool> vst(n + 1);
    vector<pair<int, int>> dlls;
    for (int i = 1; i <= n; i++) {
        if (vst[i]) {
            continue;
        }

        deque<int> dq;
        dq.push_back(i);
        vst[i] = true;
        while (adjl[dq.front()].first != 0 || adjl[dq.back()].second != 0) {
            if (adjl[dq.front()].first != 0) {
                dq.push_front(adjl[dq.front()].first);
                vst[dq.front()] = true;
            }
            
            if (adjl[dq.back()].second != 0) {
                dq.push_back(adjl[dq.back()].second);
                vst[dq.back()] = true;
            }
        }

        dlls.push_back({dq.front(), dq.back()});
    }

    int len = dlls.size();
    for (int i = 0; i < len - 1; i++) {
        adjl[dlls[i].second].second = dlls[i + 1].first;
        adjl[dlls[i + 1].first].first = dlls[i].second;
    }

    for (int i = 1; i <= n; i++) {
        cout << adjl[i].first << ' ' << adjl[i].second << endl; 
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