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

int linkedGrp(int f, vector<pair<int, int>> &linked_floors) {
    if (f < linked_floors[0].first) {
        return -1;
    }

    int grp = upper_bound(linked_floors.begin(), linked_floors.end(), make_pair(f, INF32)) - linked_floors.begin() - 1;

    if (f > linked_floors[grp].second) {
        return -1;
    }

    return grp;
}

int elevatorIdx(int a, int f, map<int, vector<pair<int, int>>> &merg_ranges) {
    if (merg_ranges[a].empty()) {
        return -1;
    }

    if (f < merg_ranges[a][0].first) {
        return -1;
    }

    int ele = upper_bound(merg_ranges[a].begin(), merg_ranges[a].end(), make_pair(f, INF32)) - merg_ranges[a].begin() - 1;

    if (f > merg_ranges[a][ele].second) {
        return -1;
    }

    return ele;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> ranges;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        ranges.push_back({b, c, a});
    }

    sort(ranges.begin(), ranges.end());
    map<int, vector<pair<int, int>>> merg_ranges;
    vector<pair<int, int>> linked_floors;
    for (auto &[b, c, a] : ranges) {
        if (merg_ranges[a].empty()) {
            merg_ranges[a].push_back({b, c});
        } else if (b <= merg_ranges[a].back().second) {
            merg_ranges[a].back().second = max(merg_ranges[a].back().second, c);
        } else {
            merg_ranges[a].push_back({b, c});
        }

        if (linked_floors.empty()) {
            linked_floors.push_back({b, c});
        } else if (b <= linked_floors.back().second) {
            linked_floors.back().second = max(linked_floors.back().second, c);
        } else {
            linked_floors.push_back({b, c});
        }
    }

    /*
    cout << "|||||||||||||||linked_floors|||||||||||||||" << endl;
    for (auto &[x, y] : linked_floors) {
        cout << x << ' ' << y << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    vector<pair<int, int>> all_merg_ranges;
    for (auto &[a, v] : merg_ranges) {
        for (auto &[b, c] : v) {
            all_merg_ranges.push_back({b, c});
        }
    }
    sort(all_merg_ranges.begin(), all_merg_ranges.end());
    vector<tuple<int, int, int>> highest_floor;
    for (auto &[b, c] : all_merg_ranges) {
        if (highest_floor.empty()) {
            highest_floor.push_back({b, c, c});
        } else if (b == get<0>(highest_floor.back())) {
            if (c > get<1>(highest_floor.back())) {
                get<1>(highest_floor.back()) = c;
                get<2>(highest_floor.back()) = c;
            }
        } else if (b > get<0>(highest_floor.back()) && b <= get<1>(highest_floor.back())) {
            if (c > get<1>(highest_floor.back())) {
                get<1>(highest_floor.back()) = b - 1;
                highest_floor.push_back({b, c, c});
            }
        } else {
            highest_floor.push_back({b, c, c});
        }
    }

    /*
    cout << "|||||||||||||||highest_floor|||||||||||||||" << endl;
    for (auto &[x, y, z] : highest_floor) {
        cout << x << ' ' << y << ' ' << z << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    map<int, int> comp, decomp;
    for (auto &[a, v] : merg_ranges) {
        for (auto &[b, c] : v) {
            comp[c] = -1;
        }
    }
    int len = 0;
    for (auto &[k, ck] : comp) {
        comp[k] = len;
        decomp[len] = k;
    
        len++;
    }

    int len_log2 = log2(len);
    // dp[i][j] is highest floor reachable with 2^i skybridges given floor j
    vector<vector<int>> dp(len_log2 + 1, vector<int>(len)); 
    for (int j = 0; j < len; j++) {
        int idx = upper_bound(highest_floor.begin(), highest_floor.end(), make_tuple(decomp[j], INF32, INF32)) - highest_floor.begin() - 1;
        dp[0][j] = comp[get<2>(highest_floor[idx])];
    }
    for (int i = 1; i <= len_log2; i++) {
        for (int j = 0; j < len; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    /*
    cout << "|||||||||||||||dp|||||||||||||||" << endl;
    for (int i = 0; i < len; i++) {
        cout << decomp[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i <= len_log2; i++) {
        for (int j = 0; j < len; j++) {
            cout << decomp[dp[i][j]] << ' ';
        }
        cout << endl;
    }
    cout << "||||||||||||||||||||||||||||||||" << endl;
    //*/

    while (q--) {
        int x, y, z, w; // building x, floor y to building z, floor w
        cin >> x >> y >> z >> w;

        if (y == w) {
            cout << (x == z ? 0 : 1) << endl;
            continue;
        }

        if (y > w) { // swap when destination on lower floor so that we always go up
            swap(x, z);
            swap(y, w);
        }

        int y_grp = linkedGrp(y, linked_floors);
        int w_grp = linkedGrp(w, linked_floors);
        if (y_grp == -1 || w_grp == -1 || y_grp != w_grp) {
            cout << -1 << endl;
            continue;
        }

        int ans = w - y;
        int y_ele_idx = elevatorIdx(x, y, merg_ranges), y_new = 0;
        if (y_ele_idx != -1) {
            y_new = merg_ranges[x][y_ele_idx].second;
        } else {
            ans++;

            int idx = upper_bound(highest_floor.begin(), highest_floor.end(), make_tuple(y, INF32, INF32)) - highest_floor.begin() - 1;
            y_new = get<2>(highest_floor[idx]);
        }

        int w_ele_idx = elevatorIdx(z, w, merg_ranges), w_new = w;
        if (w_ele_idx != -1) {
            w_new = merg_ranges[z][w_ele_idx].first;
        }

        if (y_new >= w_new) {
           if (y_ele_idx != -1) {
                cout << ans + (x == z ? 0 : 1) << endl;
            } else {
                cout << ans + (y >= w_new ? 0 : 1) << endl;
            }
            continue;
        }
        
        for (int i = len_log2; i >= 0; i--) {
            if (decomp[dp[i][comp[y_new]]] < w_new) {
                ans += 1 << i;
                y_new = decomp[dp[i][comp[y_new]]];
            }
        }
        
        cout << ans + 2 << endl; 
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