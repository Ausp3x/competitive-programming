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
    int N, K, T;
    cin >> N >> K >> T;
    vector<int> S(N + 2);
    S[0] = S[N + 1] = INF32;
    for (int i = 1; i <= N; i++)
        cin >> S[i];
    vector<bool> is_indiv(N + 2);
    vector<int> A(K);
    is_indiv[0] = is_indiv[N + 1] = true;
    for (int &a : A) {
        cin >> a;
        is_indiv[a] = true;
    }
    A.pb(0);
    A.pb(N + 1);
    
    sort(A.begin(), A.end());

    if (K == 0) {
        cout << 0 << endl;
        return;
    }

    int lft = 0;
    vector<lng> prf(N + 2);
    for (int i = 1; i <= N; i++) {
        if (is_indiv[i]) {
            lft = i;
            continue;
        }
        
        prf[i] = prf[i - 1] + S[i] - S[lft];
    }

    // for (lng x : prf)
    //     cout << x << ' ';
    // cout << endl;

    int rht = N + 1;
    vector<lng> suf(N + 2);
    for (int i = N; i >= 1; i--) {
        if (is_indiv[i]) {
            rht = i;
            continue;
        }

        suf[i] = suf[i + 1] + S[i] - S[rht];
    }

    // for (lng x : suf)
    //     cout << x << ' ';
    // cout << endl;

    vector<lng> prf_max(N + 2);
    for (int i = 1; i <= N; i++) {
        if (is_indiv[i]) 
            continue;
        
        prf_max[i] = max(prf_max[i - 1], prf[i]);
    }

    // for (auto x : prf_max)
    //     cout << x << ' ';
    // cout << endl;

    vector<lng> suf_max(N + 2);
    for (int i = N; i >= 1; i--) {
        if (is_indiv[i])
            continue;

        suf_max[i] = max(suf_max[i + 1], suf[i]);
    }

    // for (auto x : suf_max)
    //     cout << x << ' ';
    // cout << endl;

    vector<tuple<lng, lng, lng>> V;
    for (int i = 0; i <= K; i++) {
        if (A[i] + 1 == A[i + 1])
            continue;
        
        lng bst = -INF64;
        for (int j = A[i]; j < A[i + 1]; j++) 
            bst = max(bst, prf[j] + suf[j + 1]);

        lng bst_max = -INF64;
        for (int j = A[i]; j < A[i + 1]; j++) 
            bst_max = max(bst_max, prf_max[j] + suf_max[j + 1]);
            
        V.pb({bst_max - bst, bst_max, bst});
    }

    sort(V.begin(), V.end());

    // for (auto [x, y, z] : V)
    //     cout << x << ' ' << y << ' ' << z << endl;

    int cnt = T - K;
    lng ans = 0;
    while (!V.empty()) {
        auto [profit, bst_max, bst] = V.back();

        if (bst_max == bst) {
            ans += bst_max;
            V.pop_back();
            continue;
        }

        if (cnt > 0) {
            ans += bst_max;
            cnt--;
            V.pop_back();
            continue;
        }

        ans += bst;
        V.pop_back();
    }

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