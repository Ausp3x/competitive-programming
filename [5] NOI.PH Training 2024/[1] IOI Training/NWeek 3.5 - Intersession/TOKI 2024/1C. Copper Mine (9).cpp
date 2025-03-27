// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "copper.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng min_risk(int N, int M, int L, vector<int> U, vector<int> V, vector<int> A, vector<int> S) {
    bool subtask_1_chk = (M == N);
    for (int i = 0; i < N - 1; i++)
        subtask_1_chk &= (U[i] == i) & (V[i] == i + 1);

    if (subtask_1_chk) {
        vector<int> button_order(N);
        for (int i = 0; i < N; i++)
            button_order[A[i]] = i;

        // for (int x : button_order)
        //     cout << x << ' ';
        // cout << endl;

        vector<int> pref_lr(N);
        pref_lr[0] = 0;
        for (int i = 1; i < N; i++)
            pref_lr[i] = pref_lr[i - 1] + (button_order[i] < button_order[i - 1]);

        // for (int x : pref_lr)
        //     cout << x << ' ';
        // cout << endl;

        vector<int> pref_rl(N);
        pref_rl[N - 1] = 0;
        for (int i = N - 2; i >= 0; i--)
            pref_rl[i] = pref_rl[i + 1] + (button_order[i] < button_order[i + 1]);

        // for (int x : pref_rl)
        //     cout << x << ' ';
        // cout << endl;

        int prv = 0;
        lng ans = 0;
        for (int cur : S) {
            if (cur >= prv)
                ans += pref_lr[cur] - pref_lr[prv];
            else
                ans += pref_rl[cur] - pref_rl[prv];

            prv = cur;
        }

        return ans;
    }

    return -1;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        int N, M, L;
        cin >> N >> M >> L;
        vector<int> U(N - 1), V(N - 1);
        for (int &u : U)
            cin >> u;
        for (int &v : V)
            cin >> v;
        vector<int> A(M);
        for (int &a : A)
            cin >> a;
        vector<int> S(L);
        for (int &s : S)
            cin >> s;
        
        cout << min_risk(N, M, L, U, V, A, S) << endl;
    }

    return 0;
}
#endif