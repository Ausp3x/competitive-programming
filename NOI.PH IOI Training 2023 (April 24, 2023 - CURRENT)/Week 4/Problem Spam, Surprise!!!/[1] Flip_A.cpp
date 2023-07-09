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

    int cur = 0;
    vector<int> cnts(n + 1), max_cnts(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur++;
        } else if (s[i] == '1') {
            cur--;
        }

        cnts[i + 1] = cur;
        max_cnts[i + 1] = max(max_cnts[i], cur);
    }
    /*
    for (int x : cnts) {
        cout << x << ' ';
    }
    cout << endl;
    for (int x : max_cnts) {
        cout << x << ' ';
    }
    cout << endl;
    //*/
    int ans = 1e9, ones = count(s.begin(), s.end(), '1');
    for (int i = 1; i <= n; i++) {
        ans = min(ans, ones + cnts[i] - max_cnts[i - 1]);
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