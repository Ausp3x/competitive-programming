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
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            A[i][j] = x - '0';
        }
    vector<vector<int>> B(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            B[i][j] = x - '0';
        }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) 
            while (A[i][j] != B[i][j]) {
                (A[i][j] += 1) %= 3;
                (A[i][j + 1] += 2) %= 3;
                (A[i + 1][j] += 2) %= 3;
                (A[i + 1][j + 1] += 1) %= 3;
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i][j] != B[i][j]) {
                cout << "NO" << endl;
                return;
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