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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> heights[i][j];

    lng h_sums = 0;
    vector<vector<int>> states(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == '0')
                h_sums += heights[i][j];
            else
                h_sums -= heights[i][j];
            if (x == '0')   
                states[i + 1][j + 1] = 1;
            else
                states[i + 1][j + 1] = -1;
        }

    if (h_sums == 0) {
        cout << "YES" << endl;
        return;
    }

    h_sums = abs(h_sums);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            states[i][j] += states[i - 1][j] + states[i][j - 1] - states[i - 1][j - 1];

    set<int> net_difs;
    for (int i = 0; i <= n - k; i++)
        for (int j = 0; j <= m - k; j++) {
            int net_dif = states[i + k][j + k] - states[i + k][j] - states[i][j + k] + states[i][j];
            net_difs.insert(abs(net_dif));
        }
            
    // cout << "TARGET: " << h_sums << endl;
    // cout << "VALUES: ";
    // for (int x : net_difs)
    //     cout << x << ' ';    
    // cout << endl;
    // cout << endl;

    int gcf = 0;
    for (int x : net_difs)
        gcf = __gcd(gcf, x);

    if (gcf == 0) {
        cout << "NO" << endl;
        return;
    }

    cout << (h_sums % gcf == 0 ? "YES" : "NO") << endl;

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