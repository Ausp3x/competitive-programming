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
    string s;
    cin >> s;

    if (s == "1") {
        cout << 1 << endl;
        return;
    }

    if (count(s.begin(), s.end(), '1') == 1) {
        cout << 0 << endl;
        return;
    }

    int ans = 1e9;
    for (int t = 0; t < 2; t++) {
        int cur = 1e9, cnt = 0, max_cnt = 0, max_cnt_idx = -1;
        int bgn = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
            } else if (s[i] == '1') {
                cnt--;
            }

            if (cnt - max_cnt < cur) {
                cur = cnt - max_cnt;
                bgn = max_cnt_idx + 1;
                end = i;
            }

            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_cnt_idx = i;
            }
        }

        int ones = count(s.begin(), s.end(), '1');
        ans = min(ans, ones + cur);

        for (int i = bgn; i <= end; i++) {
            s[i] = '0' + ((s[i] - '0') ^ 1);
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