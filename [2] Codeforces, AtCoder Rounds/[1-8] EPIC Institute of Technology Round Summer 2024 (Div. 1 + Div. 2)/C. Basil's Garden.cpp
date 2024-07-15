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

// bool isDone(vector<int> hs) {
//     for (int h : hs)
//         if (h > 0)
//             return false;

//     return true;
// }

void solve(int t) {
    int n;
    cin >> n;
    vector<int> hs(n);
    for (int &h : hs)
        cin >> h;

    // for (int h : hs)
    //     cout << h << ' ';
    // cout << endl;

    // int cnt = 0;
    // while (true) {
    //     for (int i = 0; i < n - 1; i++)
    //         if (hs[i] > hs[i + 1])
    //             hs[i]--;
    //     if (hs[n - 1] > 0)
    //         hs[n - 1]--;

    //     for (int h : hs)
    //         cout << h << ' ';
    //     cout << endl;

    //     cnt++;
    //     if (isDone(hs))
    //         break;
    // }
    // cout << endl;

    // cout << cnt << endl;

    int ans = hs[n - 1];
    for (int i = n - 2; i >= 0; i--)
        ans = max(hs[i], ans + 1);

    cout << ans << endl;

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