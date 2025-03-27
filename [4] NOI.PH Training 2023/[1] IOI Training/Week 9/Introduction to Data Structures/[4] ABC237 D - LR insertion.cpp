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
    string s;
    cin >> s;

    deque<int> ans;
    ans.push_back(n);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            ans.push_back(i);
        } else if (s[i] == 'R') {
            ans.push_front(i);
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
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