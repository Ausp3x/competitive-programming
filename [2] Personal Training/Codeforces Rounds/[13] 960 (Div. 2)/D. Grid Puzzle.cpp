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

int n;
vector<int> A;

int n2 = 5;
vector<vector<int>> memo;
vector<vector<int>> opts = {{0}, {1}, {2}, {3}, {0, 2}, {1, 3}};

bool covers(int msk, int len) {
    if (len > 5)
        return false;

    for (int i = 0; i < len; i++)
        if (!(msk & (1 << i)))
            return false;

    return true;
}

int dp(int i, int msk) {
    if (i == n)
        return 0;

    if (memo[i][msk] != -1)
        return memo[i][msk];

    int bst = dp(i + 1, 0) + 1;
    if (covers(msk, A[i]))
        bst = min(bst, dp(i + 1, 0));
    
    if (A[i] <= 5) {
        for (auto opt : opts) {
            int cur_msk = msk, new_msk = 0;
            for (int pos : opt) {
                cur_msk |= 3 << pos;
                new_msk |= 3 << pos;
            }

            if (covers(cur_msk, A[i]))
                bst = min(bst, int(opt.size()) + dp(i + 1, new_msk));
        }
    }

    return memo[i][msk] = bst;
}

void solve() {
    cin >> n;
    A.clear();
    A.resize(n);
    for (int &a : A)
        cin >> a;

    if (n == 1) {
        cout << (A[0] != 0) << endl;
        return;
    }

    memo.clear();
    memo.resize(n, vector<int>(1 << n2, -1));

    cout << dp(0, 0) << endl;

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