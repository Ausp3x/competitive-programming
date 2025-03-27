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
    int n;
    cin >> n;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }

    int bgn = 0;
    while (as[bgn] == 1 && bgn < n) {
        bgn++;
    }

    if (bgn == n) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }

    int end = n - 1;
    while (as[end] == 1) {
        end--;
    }

    lng prd = 1;
    for (int i = bgn; i <= end; i++) {
        prd *= as[i];

        if (prd >= 2 * n) {
            cout << bgn + 1 << ' ' << end + 1 << endl;
            return;
        }
    }

    vector<pair<int, int>> ranges, sums_prds;
    ranges.push_back({bgn, bgn});
    sums_prds.push_back({as[bgn], as[bgn]});
    for (int i = bgn + 1; i <= end; i++) {
        if (as[i] == 1 && as[i - 1] > 1) {
            ranges.push_back({i, i});
            sums_prds.push_back({1, 1});
        } else {
            ranges.back().second = i;
            sums_prds.back().first += as[i];
            sums_prds.back().second *= as[i];
        }
    }

    if (ranges.size() == 1) {
        cout << ranges[0].first + 1 << ' ' << ranges[0].second + 1 << endl;
        return;
    }

    /*
    cout << "|||||||||||||||ranges|||||||||||||||" << endl;
    for (auto &[x, y] : ranges) {
        cout << x << ' ' << y << endl;
    }
    cout << "||||||||||||||||||||||||||||||||||||" << endl;
    //*/
    
    /*
    cout << "|||||||||||||||sums_prds|||||||||||||||" << endl;
    for (auto &[x, y] : sums_prds) {
        cout << x << ' ' << y << endl;
    }
    cout << "|||||||||||||||||||||||||||||||||||||||" << endl;
    //*/

    int l = 1, r = 1, d = 0;
    int len = ranges.size();
    for (int i = 0; i < len; i++) {
        while (as[ranges[i].first] == 1) {
            ranges[i].first++;
            sums_prds[i].first--;
        }

        int cur_s = 0, cur_p = 1;
        for (int j = i; j < len; j++) {
            cur_s += sums_prds[j].first;
            cur_p *= sums_prds[j].second;
        
            if (cur_p - cur_s > d) {
                l = ranges[i].first + 1;
                r = ranges[j].second + 1;
                d = cur_p - cur_s;
            }
        }
    }

    cout << l << ' ' << r << endl;

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