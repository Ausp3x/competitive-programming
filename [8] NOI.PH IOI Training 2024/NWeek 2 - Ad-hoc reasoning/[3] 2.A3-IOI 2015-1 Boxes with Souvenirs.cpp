// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng delivery(int N, int K, int L, int positions[]) {
    sort(positions, positions + N);

    vector<lng> prf(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prf[i] = 2 * positions[i - 1];
        if (i - K >= 0)
            prf[i] += prf[i - K];
    }

    vector<lng> suf(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = 2 * (L - positions[i]);
        if (i + K <= N)
            suf[i] += suf[i + K];
    }

    lng ans = INF64;
    for (int i = 0; i <= N; i++) {
        ans = min(ans, prf[i] + suf[i]);
        if (i + K <= N)
            ans = min({ans, prf[i] + suf[i + K] + L, prf[i + K] + suf[i] + L});
    }

    return ans;
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int N, K, L;
        cin >> N >> K >> L;
        int positions[N];
        for (int i = 0; i < N; i++)
            cin >> positions[i];

        cout << delivery(N, K, L, positions) << endl;
    }

    return 0;
}
//*/