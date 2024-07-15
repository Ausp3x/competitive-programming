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
    vector<vector<int>> rects, one_r1, one_r2, two_r;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        rects.push_back({r1, c1, r2, c2});
        if (r1 == r2) {
            if (r1 == 1) {
                one_r1.push_back({c1, c2, i});
            } else if (r1 == 2) {
                one_r2.push_back({c1, c2, i});
            }
        } else {
            two_r.push_back({c1, c2, i});
        }
    }

    sort(one_r1.begin(), one_r1.end());
    sort(one_r2.begin(), one_r2.end());
    sort(two_r.begin(), two_r.end());

    vector<vector<int>> pone_r1;
    if (!one_r1.empty()) {
        pone_r1.push_back(one_r1[0]);
    }
    for (int i = 1; i < one_r1.size(); i++) {
        if (one_r1[i][1] <= pone_r1.back()[1]) {
            rects[one_r1[i][2]] = {0, 0, 0, 0};
            continue;
        }
        
        rects[one_r1[i][2]][1] = max(one_r1[i][0], pone_r1.back()[1] + 1);
        one_r1[i][0] = rects[one_r1[i][2]][1];
        pone_r1.push_back(one_r1[i]);
    }

    vector<vector<int>> pone_r2;
    if (!one_r2.empty()) {
        pone_r2.push_back(one_r2[0]);
    }
    for (int i = 1; i < one_r2.size(); i++) {
        if (one_r2[i][1] <= pone_r2.back()[1]) {
            rects[one_r2[i][2]] = {0, 0, 0, 0};
            continue;
        }
        
        rects[one_r2[i][2]][1] = max(one_r2[i][0], pone_r2.back()[1] + 1);
        one_r2[i][0] = rects[one_r2[i][2]][1];
        pone_r2.push_back(one_r2[i]);
    }
    
    lng ans = 0;
    vector<vector<int>> ptwo_r;
    if (!two_r.empty()) {
        ans += 2 * (two_r[0][1] - two_r[0][0] + 1);
        ptwo_r.push_back(two_r[0]);
    }
    for (int i = 1; i < two_r.size(); i++) {
        if (two_r[i][1] <= ptwo_r.back()[1]) {
            rects[two_r[i][2]] = {0, 0, 0, 0};
            continue;
        }
        
        rects[two_r[i][2]][1] = max(two_r[i][0], ptwo_r.back()[1] + 1);
        two_r[i][0] = rects[two_r[i][2]][1];
        ans += 2 * (two_r[i][1] - two_r[i][0] + 1);
        ptwo_r.push_back(two_r[i]);
    }

    int j = 0;
    for (int i = 0; i < pone_r1.size(); i++) {
        if (j == ptwo_r.size()) {
            ans += pone_r1[i][1] - pone_r1[i][0] + 1;
            continue;
        }
        
        while (j < ptwo_r.size()) {
            if (ptwo_r[j][1] < pone_r1[i][0]) {
                j++;
                continue;
            }

            if (ptwo_r[j][0] > pone_r1[i][1]) {
                break;
            }

            if (ptwo_r[j][0] <= pone_r1[i][0] && pone_r1[i][1] <= ptwo_r[j][1]) {
                rects[pone_r1[i][2]] = {0, 0, 0, 0};
                goto jump1; 
            }
        
            if (ptwo_r[j][0] < pone_r1[i][0] && pone_r1[i][0] <= ptwo_r[j][1]) {
                rects[pone_r1[i][2]][1] = ptwo_r[j][1] + 1;
                j++;
            } else if (ptwo_r[j][0] <= pone_r1[i][1] && pone_r1[i][1] < ptwo_r[j][1]) {
                rects[pone_r1[i][2]][3] = ptwo_r[j][0] - 1;
                break;
            } else {
                rects[ptwo_r[j][2]][0] = 2;
                ans -= ptwo_r[j][1] - ptwo_r[j][0] + 1;
                j++;
            }
        }

        if (rects[pone_r1[i][2]][1] > rects[pone_r1[i][2]][3]) {
            rects[pone_r1[i][2]] = {0, 0, 0, 0};
        } else {
            ans += rects[pone_r1[i][2]][3] - rects[pone_r1[i][2]][1] + 1;
        }

    jump1:
    }

    j = 0;
    for (int i = 0; i < pone_r2.size(); i++) {
        if (j == ptwo_r.size()) {
            ans += pone_r2[i][1] - pone_r2[i][0] + 1;
            continue;
        }
        
        while (j < ptwo_r.size()) {
            if (ptwo_r[j][1] < pone_r2[i][0]) {
                j++;
                continue;
            }

            if (ptwo_r[j][0] > pone_r2[i][1]) {
                break;
            }

            if (ptwo_r[j][0] <= pone_r2[i][0] && pone_r2[i][1] <= ptwo_r[j][1]) {
                rects[pone_r2[i][2]] = {0, 0, 0, 0};
                goto jump2; 
            }
        
            if (ptwo_r[j][0] < pone_r2[i][0] && pone_r2[i][0] <= ptwo_r[j][1]) {
                rects[pone_r2[i][2]][1] = ptwo_r[j][1] + 1;
                j++;
            } else if (ptwo_r[j][0] <= pone_r2[i][1] && pone_r2[i][1] < ptwo_r[j][1]) {
                rects[pone_r2[i][2]][3] = ptwo_r[j][0] - 1;
                break;
            } else {
                rects[ptwo_r[j][2]][2] = 1;
                ans -= ptwo_r[j][1] - ptwo_r[j][0] + 1;
                j++;
            }
        }

        if (rects[pone_r2[i][2]][1] > rects[pone_r2[i][2]][3]) {
            rects[pone_r2[i][2]] = {0, 0, 0, 0};
        } else {
            ans += rects[pone_r2[i][2]][3] - rects[pone_r2[i][2]][1] + 1;
        }

    jump2:
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (rects[i][0] > rects[i][2]) {
            cout << "0 0 0 0" << endl;
        } else {
            cout << rects[i][0] << ' ' << rects[i][1] << ' ' << rects[i][2] << ' ' << rects[i][3] << endl;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // break;
    }

    return 0;
}