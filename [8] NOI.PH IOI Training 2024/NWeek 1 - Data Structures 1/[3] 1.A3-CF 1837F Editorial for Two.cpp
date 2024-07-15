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
    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }

    lng ans = -1, l = 1, r = 1000000000ll * k;
    while (l <= r) {
        lng md = (l + r) / 2;

        lng left = 0;
        vector<int> lcnts(n);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            left += as[i];
            pq.push(as[i]);

            while (left > md) {
                left -= pq.top();
                pq.pop();
            }

            lcnts[i] = pq.size();
        }

        lng right = 0;
        vector<int> rcnts(n);
        pq = priority_queue<int>();
        for (int i = n - 1; i >= 0; i--) {
            right += as[i];
            pq.push(as[i]);

            while (right > md) {
                right -= pq.top();
                pq.pop();
            }

            rcnts[i] = pq.size();
        }

        bool isPossible = lcnts[n - 1] >= k || rcnts[0] >= k;
        for (int i = 0; i < n - 1; i++)
            if (lcnts[i] + rcnts[i + 1] >= k) {
                isPossible = true;
                break;
            }
        
        // cout << md << endl;
        // for (int x : lcnts)
        //     cout << x << ' ';
        // cout << endl;
        // for (int x : rcnts)
        //     cout << x << ' ';
        // cout << endl;

        if (isPossible) {
            ans = md;
            r = md - 1;
        } else 
            l = md + 1;
    }

    cout << ans << endl;

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