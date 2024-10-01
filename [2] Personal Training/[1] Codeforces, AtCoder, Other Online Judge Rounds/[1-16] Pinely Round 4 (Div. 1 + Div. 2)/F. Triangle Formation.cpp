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

vector<int> B;
bool isBothNonDegenerate(int t10, int t11, int t12, int t20, int t21, int t22) {
    assert(t10 != t11 && t10 != t12 && t11 != t12);
    assert(t20 != t21 && t20 != t22 && t21 != t22);
    return B[t10] + B[t11] > B[t12] && B[t20] + B[t21] > B[t22];
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int &a : A) {
        cin >> a;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (r - l + 1 > 50) {
            cout << "YES" << endl;
            continue;
        }

        B.clear();
        for (int i = l; i <= r; i++)
            B.pb(A[i]);

        sort(B.begin(), B.end());

        bool is_good = false;
        for (int i = 2; i + 3 < B.size(); i++) {
            // 1-apart
            is_good |= isBothNonDegenerate(i - 1, i, i + 2, i - 2, i + 1, i + 3);
            is_good |= isBothNonDegenerate(i - 1, i, i + 3, i - 2, i + 1, i + 2);
            is_good |= isBothNonDegenerate(i - 2, i, i + 2, i - 1, i + 1, i + 3);
            is_good |= isBothNonDegenerate(i - 2, i, i + 3, i - 1, i + 1, i + 2);
        
            // 2-apart
            is_good |= isBothNonDegenerate(i - 2, i - 1, i + 2, i, i + 1, i + 3);
            is_good |= isBothNonDegenerate(i - 2, i - 1, i + 3, i, i + 1, i + 2);
            is_good |= isBothNonDegenerate(i - 1, i, i + 1,     i - 2, i + 2, i + 3);
            is_good |= isBothNonDegenerate(i - 2, i, i + 1,     i - 1, i + 2, i + 3);
        }

        int ll = 1;
        while (ll + 1 < B.size() && !isBothNonDegenerate(ll - 1, ll, ll + 1, ll - 1, ll, ll + 1))
            ll++;

        int rr = B.size() - 2;
        while (rr - 1 >= 0 && !isBothNonDegenerate(rr - 1, rr, rr + 1, rr - 1, rr, rr + 1))
            rr--;

        is_good |= rr - ll >= 3;
        
        cout << (is_good ? "YES\n" : "NO\n");
    }
    
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