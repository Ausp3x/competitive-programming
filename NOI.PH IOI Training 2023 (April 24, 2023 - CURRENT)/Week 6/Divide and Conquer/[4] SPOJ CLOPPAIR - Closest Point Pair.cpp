// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> points; 
    map<pair<int, int>, int> point_idxs;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[x].push_back(y);
        point_idxs[{x, y}] = i;
    }

    for (auto &[x, ys] : points) {
        sort(ys.begin(), ys.end());
    }

    int a = -1, b = -1;
    lng min_d_sq = 1e18;
    set<pair<int, int>> points_to_be_checked;
    for (auto &[x, ys] : points) {
        int len = ys.size();
        lng cur_d_sq = 1e18;
        for (int i = 0; i < len - 1; i++) {
            cur_d_sq = 1ll * (ys[i] - ys[i + 1]) * (ys[i] - ys[i + 1]);    
            if (cur_d_sq < min_d_sq) {
                a = point_idxs[{x, ys[i]}];
                b = point_idxs[{x, ys[i + 1]}];
                min_d_sq = cur_d_sq;
            }
        }

        for (int &y : ys) {
            while (!points_to_be_checked.empty()) {
                if (min_d_sq >= 1ll * (x - points_to_be_checked.begin()->first) * (x - points_to_be_checked.begin()->first)) {
                    break;
                }

                points_to_be_checked.erase(points_to_be_checked.begin());
            }

            for (auto &[x2, y2] : points_to_be_checked) {
                if (x2 == x) {
                    break;
                }

                cur_d_sq = 1ll * (x - x2) * (x - x2) + 1ll * (y - y2) * (y - y2);
                if (cur_d_sq < min_d_sq) {
                    a = point_idxs[{x, y}];
                    b = point_idxs[{x2, y2}];
                    min_d_sq = cur_d_sq;
                }
            }

            points_to_be_checked.insert({x, y});
        }
    }

    if (a > b) {
        swap(a, b);
    }

    cout << a << ' ' << b << ' ' << fixed << setprecision(6) << sqrtl(min_d_sq) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}