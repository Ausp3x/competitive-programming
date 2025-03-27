// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<int> isNotMiddle(n + 1, true);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        isNotMiddle[b] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!isNotMiddle[i])
            continue;

        for (int j = 1; j <= n; j++) {
            if (j == i)
                continue;

            cout << i << ' ' << j << endl;
            
        }
        return;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}