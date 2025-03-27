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
    vector<pair<int, int>> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i].first;
        as[i].second = i + 1;
    }

    sort(as.begin(), as.end(), greater<pair<int, int>>());

    int i = 0;
    vector<int> ans(n);
    for (; k * i < n; i++) {
        ans[k * i] = as[i].second;    
    }

    for (int j = 0; j < n; j++) {
        if (j % k == 0) {
            continue;
        }

        ans[j] = as[i].second;
        i++;
    }

    for (int x : ans) {
        cout << x << ' '; 
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