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
    lng n;
    cin >> n;
    
    lng nn = n;
    int pow2 = 0;
    vector<int> pow2s;
    while (nn > 0) {
        if (nn & 1)
            pow2s.pb(pow2);

        nn /= 2;
        pow2++;
    }

    vector<lng> ans;
    ans.pb(n);
    for (int x : pow2s)
        ans.pb(n ^ (1ll << x));
    
    if (ans.back() == 0)
        ans.pop_back();
    
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (lng x : ans)
        cout << x << ' ';
    cout << endl;

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