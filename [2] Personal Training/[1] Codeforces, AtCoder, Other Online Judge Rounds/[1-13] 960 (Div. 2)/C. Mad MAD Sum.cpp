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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    
    lng sum = accumulate(A.begin(), A.end(), 0ll);

    int cur = 0;
    map<int, int> cnts;
    vector<int> B(n);
    cnts[0] = INF32;
    for (int i = 0; i < n; i++) {
        cnts[A[i]]++;
        if (A[i] > cur && cnts[A[i]] > 1)
            cur = A[i];

        B[i] = cur;
    }

    // for (int b : B)
    //     cout << b << ' ';
    // cout << endl;

    sum += accumulate(B.begin(), B.end(), 0ll);

    cur = 0;
    cnts.clear();
    vector<lng> C(n);
    cnts[0] = INF32;
    for (int i = 0; i < n; i++) {
        cnts[B[i]]++;
        if (B[i] > cur && cnts[B[i]] > 1)
            cur = B[i];

        C[i] = cur;
    }

    bool is_all_0 = true;
    for (int i = 0; i < n; i++)
        if (C[i] != 0) {
            is_all_0 = false;
            break;
        }

    if (is_all_0) {
        cout << sum << endl;
        return;
    }

    sum += C[0];
    for (int i = 1; i < n; i++) {
        C[i] += C[i - 1];
        sum += C[i];
    }

    cout << sum << endl;
        
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