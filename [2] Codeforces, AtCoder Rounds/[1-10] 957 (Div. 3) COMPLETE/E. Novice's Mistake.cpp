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

void solve(int t) {
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 9999 << endl;
        for (int i = 2; i <= 10000; i++)
            cout << i << ' ' << i - 1 << endl;
        return;
    }

    if (n == 2) {
        cout << 3 << endl;
        cout << 20 << ' ' << 18 << endl;
        cout << 219 << ' ' << 216 << endl;
        cout << 2218 << ' ' << 2214 << endl;
        return;
    }

    if (n == 3) {
        cout << 1 << endl;
        cout << 165 << ' ' << 162 << endl;
        return;
    }

    if (n == 4) {
        cout << 3 << endl;
        cout << 14 << ' ' << 12 << endl;
        cout << 147 << ' ' << 144 << endl;
        cout << 1480 << ' ' << 1476 << endl;
        return;
    }

    if (n == 5) {
        cout << 1 << endl;
        cout << 138 << ' ' << 135 << endl;
        return;
    }

    if (n == 6) {
        cout << 0 << endl;
        return;
    }

    if (n == 7) {
        cout << 1 << endl;
        cout << 129 << ' ' << 126 << endl;
        return;
    }

    if (n == 8) {
        cout << 0 << endl;
        return;
    }

    if (n == 9) {
        cout << 0 << endl;
        return;
    }

    if (n == 10) {
        cout << 1 << endl;
        cout << 1262 << ' ' << 2519 << endl;
        return;
    }

    if (n == 11) {
        cout << 3 << endl;
        cout << 12 << ' ' << 21 << endl;
        cout << 123 << ' ' << 242 << endl;
        cout << 1234 << ' ' << 2463 << endl;
        return;
    }

    if (n == 12) {
        cout << 0 << endl;
        return;
    }

    if (n == 13) {
        cout << 1 << endl;
        cout << 119 << ' ' << 234 << endl;
        return;
    }

    if (n == 14) {
        cout << 1 << endl;
        cout << 1178 << ' ' << 2351 << endl;
        return;
    }

    if (n == 15) {
        cout << 0 << endl;
        return;
    }

    if (n == 16) {
        cout << 1 << endl;
        cout << 1154 << ' ' << 2303 << endl;
        return;
    }

    if (n == 17) {
        cout << 0 << endl;
        return;
    }

    if (n == 18) {
        cout << 1 << endl;
        cout << 1136 << ' ' << 2267 << endl;
        return;
    }

    if (n == 19) {
        cout << 0 << endl;
        return;
    }

    if (n == 20) {
        cout << 1 << endl;
        cout << 112 << ' ' << 220 << endl;
        return;
    }

    if (n == 21) {
        cout << 1 << endl;
        cout << 11 << ' ' << 19 << endl;
        return;
    }

    if (n == 22) {
        cout << 0 << endl;
        return;
    }

    if (n == 23) {
        cout << 0 << endl;
        return;
    }

    if (n == 24) {
        cout << 1 << endl;
        cout << 110 << ' ' << 216 << endl;
        return;
    }

    if (n == 25) {
        cout << 0 << endl;
        return;
    }

    if (n == 26) {
        cout << 0 << endl;
        return;
    }

    if (n == 27) {
        cout << 0 << endl;
        return;
    }

    if (n == 28) {
        cout << 0 << endl;
        return;
    }

    if (n == 29) {
        cout << 0 << endl;
        return;
    }

    if (n == 30) {
        cout << 0 << endl;
        return;
    }

    if (n == 31) {
        cout << 0 << endl;
        return;
    }

    if (n == 32) {
        cout << 0 << endl;
        return;
    }

    if (n == 33) {
        cout << 0 << endl;
        return;
    }

    if (n == 34) {
        cout << 0 << endl;
        return;
    }

    if (n == 35) {
        cout << 1 << endl;
        cout << 107 << ' ' << 210 << endl;
        return;
    }

    if (n == 36) {
        cout << 0 << endl;
        return;
    }

    if (n == 37) {
        cout << 0 << endl;
        return;
    }

    if (n == 38) {
        cout << 0 << endl;
        return;
    }

    if (n == 39) {
        cout << 0 << endl;
        return;
    }

    if (n == 40) {
        cout << 0 << endl;
        return;
    }

    if (n == 41) {
        cout << 0 << endl;
        return;
    }

    if (n == 42) {
        cout << 0 << endl;
        return;
    }

    if (n == 43) {
        cout << 0 << endl;
        return;
    }

    if (n == 44) {
        cout << 0 << endl;
        return;
    }

    if (n == 45) {
        cout << 0 << endl;
        return;
    }

    if (n == 46) {
        cout << 0 << endl;
        return;
    }

    if (n == 47) {
        cout << 0 << endl;
        return;
    }

    if (n == 48) {
        cout << 0 << endl;
        return;
    }

    if (n == 49) {
        cout << 0 << endl;
        return;
    }

    if (n == 50) {
        cout << 0 << endl;
        return;
    }

    if (n == 51) {
        cout << 0 << endl;
        return;
    }

    if (n == 52) {
        cout << 0 << endl;
        return;
    }

    if (n == 53) {
        cout << 0 << endl;
        return;
    }

    if (n == 54) {
        cout << 0 << endl;
        return;
    }

    if (n == 55) {
        cout << 0 << endl;
        return;
    }

    if (n == 56) {
        cout << 0 << endl;
        return;
    }

    if (n == 57) {
        cout << 0 << endl;
        return;
    }

    if (n == 58) {
        cout << 0 << endl;
        return;
    }

    if (n == 59) {
        cout << 0 << endl;
        return;
    }

    if (n == 60) {
        cout << 0 << endl;
        return;
    }

    if (n == 61) {
        cout << 0 << endl;
        return;
    }

    if (n == 62) {
        cout << 0 << endl;
        return;
    }

    if (n == 63) {
        cout << 0 << endl;
        return;
    }

    if (n == 64) {
        cout << 0 << endl;
        return;
    }

    if (n == 65) {
        cout << 0 << endl;
        return;
    }

    if (n == 66) {
        cout << 0 << endl;
        return;
    }

    if (n == 67) {
        cout << 0 << endl;
        return;
    }

    if (n == 68) {
        cout << 1 << endl;
        cout << 104 << ' ' << 204 << endl;
        return;
    }

    if (n == 69) {
        cout << 0 << endl;
        return;
    }

    if (n == 70) {
        cout << 0 << endl;
        return;
    }

    if (n == 71) {
        cout << 0 << endl;
        return;
    }

    if (n == 72) {
        cout << 0 << endl;
        return;
    }

    if (n == 73) {
        cout << 0 << endl;
        return;
    }

    if (n == 74) {
        cout << 0 << endl;
        return;
    }

    if (n == 75) {
        cout << 0 << endl;
        return;
    }

    if (n == 76) {
        cout << 0 << endl;
        return;
    }

    if (n == 77) {
        cout << 0 << endl;
        return;
    }

    if (n == 78) {
        cout << 0 << endl;
        return;
    }

    if (n == 79) {
        cout << 0 << endl;
        return;
    }

    if (n == 80) {
        cout << 0 << endl;
        return;
    }

    if (n == 81) {
        cout << 0 << endl;
        return;
    }

    if (n == 82) {
        cout << 0 << endl;
        return;
    }

    if (n == 83) {
        cout << 0 << endl;
        return;
    }

    if (n == 84) {
        cout << 0 << endl;
        return;
    }

    if (n == 85) {
        cout << 0 << endl;
        return;
    }

    if (n == 86) {
        cout << 0 << endl;
        return;
    }

    if (n == 87) {
        cout << 0 << endl;
        return;
    }

    if (n == 88) {
        cout << 0 << endl;
        return;
    }

    if (n == 89) {
        cout << 0 << endl;
        return;
    }

    if (n == 90) {
        cout << 1 << endl;
        cout << 1033 << ' ' << 2061 << endl;
        return;
    }

    if (n == 91) {
        cout << 0 << endl;
        return;
    }

    if (n == 92) {
        cout << 0 << endl;
        return;
    }

    if (n == 93) {
        cout << 0 << endl;
        return;
    }

    if (n == 94) {
        cout << 1 << endl;
        cout << 1032 << ' ' << 2059 << endl;
        return;
    }

    if (n == 95) {
        cout << 0 << endl;
        return;
    }

    if (n == 96) {
        cout << 0 << endl;
        return;
    }

    if (n == 97) {
        cout << 0 << endl;
        return;
    }

    if (n == 98) {
        cout << 0 << endl;
        return;
    }

    if (n == 99) {
        cout << 0 << endl;
        return;
    }

    if (n == 100) {
        cout << 0 << endl;
        return;
    }

    // for (n = 2; n <= 10; n++) {
    //     string nS = to_string(n);
    //     vector<pair<int, int>> ans;
    //     for (int a = 1; a <= 10000; a++) {
    //         for (int b = 1; b <= min(10000, n * a); b++) {
    //             if (nS.size() * a - b >= 20)
    //                 continue;

    //             int cur = n * a - b;
    //             string curS = to_string(cur);
    //             if (nS.size() * a - b != curS.size())
    //                 continue;

    //             string cmp;
    //             for (int i = 0; i < nS.size() * a - b; i++)
    //                 cmp += nS[i % nS.size()];

    //             if (curS == cmp)
    //                 ans.push_back({a, b});
    //         }
    //     }

    //     cout << "    if (n == " << n << ") {" << endl;
    //     cout << "        cout << " << ans.size() << " << endl;" << endl;
    //     for (auto [x, y] : ans)
    //         cout << "        cout << " << x << " << ' ' << " << y << " << endl;" << endl;
    //     cout << "        return;" << endl;
    //     cout << "    }" << endl << endl;
    // }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}