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
    int n;
    cin >> n;
    vector<int> C(n);
    for (int &c : C)
        cin >> c;

    sort(C.begin(), C.end());

    if (C[0] != 1) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<bool>> pos(2, vector<bool>(5001));
    pos[0][1] = true;
    for (int i = 1; i < n; i++) {
        int i2 = !(i & 1);
        if (!pos[i2][C[i]]) {
            cout << "NO" << endl;
            return;   
        }

        for (int j = 1; j <= 5000; j++) {
            if (pos[i2][j]) {
                pos[i2 ^ 1][j] = true;
                if (j + C[i] <= 5000)
                    pos[i2 ^ 1][j + C[i]] = true;
            }
        }

        // for (int j = 0; j <= 10; j++)
        //     cout << pos[i2 ^ 1][j] << ' ';
        // cout << endl;
    }

    cout << "YES" << endl;

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