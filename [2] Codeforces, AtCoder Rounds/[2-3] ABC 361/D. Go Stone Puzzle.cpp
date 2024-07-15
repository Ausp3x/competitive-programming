// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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
    int N;
    string S;
    string T;
    cin >> N >> S >> T;

    if (S == T) {
        cout << 0 << endl;
        return;
    }

    S += "..";
    T += "..";

    map<string, int> dp;
    queue<string> q;
    dp[S] = 0;
    q.push(S);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        int empty_idx = -1;
        for (int i = 0; i < N + 1; i++)
            if (cur[i] == '.' && cur[i + 1] == '.') {
                empty_idx = i;
                break;
            }

        // cout << cur << ' ' << empty_idx << ": ";
        for (int i = 0; i < N + 1; i++) {
            if (i == empty_idx - 1 || i == empty_idx || i == empty_idx + 1)
                continue;

            string nxt = cur;
            swap(nxt[i], nxt[empty_idx]);
            swap(nxt[i + 1], nxt[empty_idx + 1]);

            if (dp[nxt] == 0) {
                dp[nxt] = dp[cur] + 1;
                q.push(nxt);
                // cout << nxt << ' ';
            }
        }
        // cout << endl;
    }

    // for (auto [k, v] : dp)
    //     cout << k << ' ' << v << endl;

    if (dp[T] == 0)
        cout << -1 << endl;
    else
        cout << dp[T] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}