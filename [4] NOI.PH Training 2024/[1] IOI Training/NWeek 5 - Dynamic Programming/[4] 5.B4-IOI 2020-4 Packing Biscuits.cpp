// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "biscuits.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng x;

int K = 60;
vector<lng> T(K), B(K);
unordered_map<lng, lng> memo;
lng dp(lng n) {
    if (n <= 0)
        return 0;

    if (memo[n] != 0) 
        return memo[n];

    int i = 63 - __builtin_clzll(n - 1);
    return memo[n] = dp(T[i]) + dp(min(B[i], n) - T[i]);
}

lng count_tastiness(lng given_x, vector<lng> A) {    
    x = given_x;
    A.resize(K);

    lng total_tastiness = 0; 
    for (int i = 0; i < K; i++) {
        if (T[i] == 0) {
            if (i == 0)
                T[i] = 1;
            else
                T[i] = 2 * T[i - 1];
        }
        total_tastiness += A[i] * T[i];
        B[i] = total_tastiness / x + 1;     
    }

    if (x > total_tastiness) 
        return 1;
    
    if (total_tastiness <= 100'000) {
        lng ans = 1;
        for (int i = 1; i <= total_tastiness / x; i++) {
            vector<lng> req_cookies(K);
            for (int j = 0; j < K; j++)
                if (i & T[j])
                    req_cookies[j] = x;

            for (int j = K - 1; j > 0; j--)
                req_cookies[j - 1] += 2 * max(req_cookies[j] - A[j], 0ll);
        
            ans += req_cookies[0] <= A[0];
        }

        #ifdef DEBUG
        cout << ans << endl;
        #endif
        #ifndef DEBUG
        return ans;
        #endif
    }

    if (x == 1) {
        for (int i = 0; i < K - 1; i++) {
            lng q = (A[i] - 1) / 2;
            A[i + 1] += q;
            A[i] -= 2 * q;
        }

        // cout << endl;
        // for (int a : A)
        //     cout << a << ' ';
        // cout << endl;
            
        int i_o = -1;
        lng cur = 0;
        vector<lng> A_reduced;
        for (int i = 0; i < K; i++) {
            if (cur < T[i]) {
                i_o = i;
                cur = 0;
                A_reduced.pb(0);
            }
            
            cur += A[i] * T[i];
            A_reduced.back() += A[i] * T[i - i_o];
        }

        lng ans = 1;
        for (lng a_r : A_reduced) {
            // cout << a_r << ' ';
            ans *= a_r + 1;
        }
        // cout << endl;

        #ifdef DEBUG
        cout << ans << endl;
        #endif
        #ifndef DEBUG
        return ans;
        #endif
    }

    memo.clear();
    memo[1] = 1;

    // cout << "All quiet on the Western front." << endl;

    return dp(1ll << K);
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int K;
        lng x;
        cin >> K >> x;
        vector<lng> A(K);
        for (lng &a : A)
            cin >> a;

        cout << count_tastiness(x, A) << endl;
    }

    return 0;
}
#endif