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
    int n, a;
    cin >> n >> a;
    vector<int> cs(n);
    for (int &c : cs) {
        cin >> c;
    }

    sort(cs.begin(), cs.end());

    int ans = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [cur, idx] = q.front();
        q.pop();

        ans = max(ans, cur);
        
        for (int i = idx; i < n; i++) {
            if (cur + cs[i] > a) {
                break;
            }

            q.push({cur + cs[i], i + 1});
        }
    }

    cout << ans << endl;

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
    cin >> t;
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