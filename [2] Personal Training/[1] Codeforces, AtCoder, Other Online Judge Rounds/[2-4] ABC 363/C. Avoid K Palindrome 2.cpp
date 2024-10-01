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

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    sort(S.begin(), S.end());

    lng ans = 0;
    do {
        bool chk = true;
        for (int i = 0; i + K - 1 < N; i++) {
            bool is_palindrome = true;
            for (int j = i; j < i + (K + 1) / 2; j++)
                if (S[j] != S[i + K - 1 - (j - i)]) {
                    is_palindrome = false;
                    break;
                }

            if (is_palindrome) {
                chk = false;
                break;
            }
        }   

        ans += chk;
    } while (next_permutation(S.begin(), S.end()));

    cout << ans << endl;

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