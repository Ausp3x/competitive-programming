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
    int N;
    lng M;
    cin >> N >> M;
    int A_max = -1;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
        A_max = max(A_max, a);
    }

    lng l = 0, r = 10000000000; 
    while (r - l > 1) {
        lng md = (l + r) / 2;

        lng cur = 0;
        for (int i = 0; i < N; i++)
            cur += min<lng>(md, A[i]);

        if (cur > M)
            r = md;
        else
            l = md; 
    }

    if (l >= A_max) {
        cout << "infinite" << endl;
        return;
    }

    cout << l << endl;

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